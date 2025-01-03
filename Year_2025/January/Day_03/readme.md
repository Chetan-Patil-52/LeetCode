## TLE after using BruteForce

### Explanation
The brute force approach results in Time Limit Exceeded (TLE) due to its inefficiency in handling large inputs. Below is an example that illustrates this issue:

<p align="center">
  <img src="https://github.com/user-attachments/assets/61cf7a79-a031-4136-a1a8-26080fb4aba2" alt="TLE BruteForce" width="600">
</p>

---

## Using Approach - 2 ( Cumulative sum) TC: O(n) && SC: O(n)

### Explanation
By using a more efficient algorithm, Approach 2 significantly reduces the computational time and avoids TLE. The optimized solution leverages better data structures and algorithms to solve the problem effectively.

<p align="center">
  <img src="https://github.com/user-attachments/assets/32c4cb78-e519-4a98-9aa8-f3098696d1dd" alt="Approach 2 Optimization" width="600">
</p>

---

## Before Optimizations Failures

### Explanation
Before optimization, the algorithm struggled to handle large input sizes efficiently, leading to performance issues.

<p align="center">
  <img src="https://github.com/user-attachments/assets/6e48d16e-f6a2-4ad1-938e-4b367f1a39f8" alt="Before TLE" width="600">
</p>

---

## After Approach - 2 (without vector) counting value of max in runtime TC: O(n) , SC: O(1)

### Explanation
After implementing optimizations, the algorithm performs efficiently, handling larger inputs without any performance bottlenecks.

<p align="center">
  <img src="https://github.com/user-attachments/assets/ac15908d-5da0-4401-8e04-80f551b96e91" alt="After TLE" width="600">
</p>
