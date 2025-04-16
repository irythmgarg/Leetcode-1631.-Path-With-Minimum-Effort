# Leetcode-1631.-Path-With-Minimum-Effort

📝 Beautiful README – Minimum Effort Path
🌟 Problem Overview
You are given an m x n grid of integers where each cell represents the height at that point. Your goal is to find a path from the top-left corner (0, 0) to the bottom-right corner (m-1, n-1) such that the maximum absolute difference in heights between any two adjacent cells along the path is minimized.

🚀 Approach Used: Modified Dijkstra’s Algorithm
🎯 Strategy:
Unlike standard Dijkstra's algorithm where we minimize the sum of weights, here we want to minimize the maximum height difference encountered along any path.
At each step, we move to the adjacent cell that allows us to maintain the minimum possible maximum effort.

🛠️ Data Structures:
Priority Queue (Min Heap): Always explore the path with the least known effort.
2D Vector ans: Stores the smallest effort to reach each cell.
Direction Array: Helps in exploring 4-directional neighbors efficiently.

🔄 Workflow:
Start from (0, 0) with 0 effort.
For each adjacent cell, calculate the effort = max(current_effort, abs(height_diff)).
Update the cell if the new effort is smaller than any previously recorded effort.
Continue until reaching (m-1, n-1).

🧠 Time and Space Complexity
Complexity	Value
⏱️ Time	O(m * n * log(m * n))
🧠 Space	O(m * n)
m = number of rows
n = number of columns

✅ Why This Works
This approach ensures you always explore paths in increasing order of maximum effort — guaranteeing that when you reach the target cell, it’s through the most optimal path possible.



📌 Example
Input:
heights = [
  [1,2,2],
  [3,8,2],
  [5,3,5]
]
Output: 2
Explanation:
The path with the smallest maximum height difference is:
(0,0) → (0,1) → (0,2) → (1,2) → (2,2)
The maximum absolute difference along this path is 2.

[Ridham Garg]-- Happy Coding
