#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Result {
    int start;
    int end;
    int sum;
    bool valid;
};

Result findMaxCrossSum(const vector<int>& resource, int low, int mid, int high, int constraint) {
    int left_sum = INT_MIN;
    int sum = 0;
    int max_left = mid;
    bool found_left = false;

    for (int i = mid; i >= low; i--) {
        sum += resource[i];
        if (sum < constraint && sum > left_sum) {
            left_sum = sum;
            max_left = i;
            found_left = true;
        }
    }

    int right_sum = INT_MIN;
    sum = 0;
    int max_right = mid + 1;
    bool found_right = false;

    for (int j = mid + 1; j <= high; j++) {
        sum += resource[j];
        if (sum < constraint && sum > right_sum) {
            right_sum = sum;
            max_right = j;
            found_right = true;
        }
    }

    Result res;
    if (found_left && found_right) {
        res.start = max_left;
        res.end = max_right;
        res.sum = left_sum + right_sum;
        if (res.sum <= constraint) {  // <= constraint
            res.valid = true;
            return res;
        }
    }

    res.valid = false;
    res.sum = INT_MIN;
    return res;
}

Result maxResult(const Result& a, const Result& b) {
    if (a.valid && b.valid)
        return (a.sum >= b.sum) ? a : b;
    else if (a.valid)
        return a;
    else if (b.valid)
        return b;
    else
        return a;
}

Result maxSubArray(const vector<int>& resource, int low, int high, int constraint) {
    if (low == high) {
        Result r;
        if (resource[low] <= constraint) {
            r.start = low;
            r.end = high;
            r.sum = resource[low];
            r.valid = true;
        } else {
            r.valid = false;
            r.sum = INT_MIN;
        }
        return r;
    }

    int mid = (low + high) / 2;
    Result leftResult = maxSubArray(resource, low, mid, constraint);
    Result rightResult = maxSubArray(resource, mid + 1, high, constraint);
    Result crossResult = findMaxCrossSum(resource, low, mid, high, constraint);

    Result max = maxResult(leftResult, rightResult);
    max = maxResult(max, crossResult);

    return max;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "No feasible subarray." << endl;
        return 0;
    }

    vector<int> resource(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> resource[i];
    }

    int constraint;
    cout << "Enter the resource constraint: ";
    cin >> constraint;

    if (constraint <= 0) {
        cout << "No feasible subarray." << endl;
        return 0;
    }

    Result finalRes = maxSubArray(resource, 0, n - 1, constraint);

    if (!finalRes.valid) {
        cout << "No feasible subarray." << endl;
    } else {
        cout << "Maximum Subarray Sum : " << finalRes.sum << endl;
        cout << "Subarray indices: " << finalRes.start << " to " << finalRes.end << endl;
        cout << "Subarray elements: ";
        for (int i = finalRes.start; i <= finalRes.end; i++) {
            cout << resource[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
