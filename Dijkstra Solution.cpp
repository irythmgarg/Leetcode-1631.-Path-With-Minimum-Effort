class Solution {
public:
    // Utility function to check if a cell (newx, newj) is within the grid bounds
    bool isSafe(int newx, int newj, int m, int n) {
        return newx >= 0 && newx < m && newj >= 0 && newj < n;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();      // Number of rows
        int n = heights[0].size();   // Number of columns

        // ans[i][j] will store the minimum effort required to reach cell (i, j)
        vector<vector<int>> ans(m, vector<int>(n, INT_MAX));

        // Using alias for cleaner code: {effort, {row, col}}
        using P = pair<int, pair<int, int>>;

        // Min-heap to explore the next cell with the smallest effort so far
        priority_queue<P, vector<P>, greater<P>> pq;

        // Directions for 4-directional movement: up, right, down, left
        vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        // Start from the top-left corner with 0 effort
        pq.push({0, {0, 0}});
        ans[0][0] = 0;

        // Dijkstra-like BFS traversal
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int diff = top.first;              // Current path's max effort
            int i = top.second.first;          // Current row
            int j = top.second.second;         // Current column

            // Explore all 4 adjacent cells
            for (auto& di : dir) {
                int newi = i + di[0];
                int newj = j + di[1];

                // If the neighbor is within bounds
                if (isSafe(newi, newj, m, n)) {
                    // Calculate the effort to move to the neighbor
                    int newEffort = max(diff, abs(heights[newi][newj] - heights[i][j]));

                    // If this path offers a smaller effort, update and push to heap
                    if (newEffort < ans[newi][newj]) {
                        ans[newi][newj] = newEffort;
                        pq.push({newEffort, {newi, newj}});
                    }
                }
            }
        }

        // Return the minimum effort to reach the bottom-right cell
        return ans[m - 1][n - 1];
    }
};
