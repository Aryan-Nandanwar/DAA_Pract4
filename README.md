# 🧮 Practical No. 4 — Maximum Sum Subarray under Resource Constraint

## 🎯 **Aim**

To implement a **divide and conquer approach** to find the **maximum sum contiguous subarray** that does **not exceed a given resource constraint**, simulating efficient resource allocation across tasks.

---

## 🧩 **Problem Description**

A project requires allocating resources to tasks over time.
Each task uses a certain number of resources given in an array `resources[]`.
The goal is to find the **subarray of consecutive tasks** that maximizes total resource usage **without exceeding the given constraint**.

If no feasible subarray exists (all exceed the constraint), the program should output **“No feasible subarray.”**

---

## ⚙️ **Approach**

* Uses the **Divide and Conquer** technique:

  * Divide the array into left and right halves.
  * Recursively find the best subarray in each half.
  * Find the best subarray that **crosses the midpoint**.
  * Combine results to get the global maximum within the constraint.

* Handles:

  * Empty arrays
  * Zero or negative constraints
  * Multiple subarrays with the same sum (returns any valid one)
  * Large input efficiently (≈ O(n log n))

---

## 💻 **Input & Output**

### **Input:**

1. Number of elements
2. Elements of the array (`resources[]`)
3. Resource constraint

### **Output:**

* Maximum subarray sum
* Subarray indices
* Elements of the subarray
* Or message: `"No feasible subarray."`

---

## 🧠 **Test Scenarios**

| No. | Input                                | Expected Behavior                   |
| --- | ------------------------------------ | ----------------------------------- |
| 1   | [2, 1, 3, 4], constraint=5           | Max sum = 4 ([2,1] or [1,3])        |
| 2   | [2, 2, 2, 2], constraint=4           | Exact match → [2,2]                 |
| 3   | [1, 5, 2, 3], constraint=5           | Single element [5]                  |
| 4   | [6, 7, 8], constraint=5              | No feasible subarray                |
| 5   | [1, 2, 3, 2, 1], constraint=5        | Multiple valid ([2,3] or [3,2])     |
| 6   | [1, 1, 1, 1, 1], constraint=4        | Long window [1,1,1,1]               |
| 7   | [4, 2, 3, 1], constraint=5           | Dynamic adjustment → [2,3]          |
| 8   | [], constraint=10                    | No subarray                         |
| 9   | [1, 2, 3], constraint=0              | No subarray                         |
| 10  | [1, 2, 3, …, 100000], constraint=10⁹ | Near full array valid (stress test) |

---

## 🧾 **Result**

The program successfully identifies the **maximum sum subarray under a given constraint** using a **divide and conquer strategy**, validating correctness across all edge and stress cases.
