class Solution {
public:
    /*
     * @param grid: a chessboard included 0 and 1
     * @return: the shortest path
     */
    int shortestPath2(vector<vector<bool>> &grid) {
        // write your code here
        int m = grid.size();
        if (m == 0) {
            return -1;
        }
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        dp[0][0] = 0;

        for (int j = 1; j < n; ++j) {
            for (int i = 0; i < m; ++i) {
                if (grid[i][j] == 0) {
                    if (i >= 1 && j >= 2 && dp[i-1][j-2] != INT_MAX) {
                        dp[i][j] = min(dp[i][j], dp[i-1][j-2] + 1);
                    }
                    if (i + 1 < m && j >= 2 && dp[i+1][j-2] != INT_MAX) {
                        dp[i][j] = min(dp[i][j], dp[i+1][j-2] + 1);
                    }
                    if (i >= 2 && j >= 1 && dp[i-2][j-1] != INT_MAX) {
                        dp[i][j] = min(dp[i][j], dp[i-2][j-1] + 1);
                    }
                    if (i + 2 < m && j >= 1 && dp[i+2][j-1] != INT_MAX) {
                        dp[i][j] = min(dp[i][j], dp[i+2][j-1] + 1);
                    }
                }
            }
        }

        return dp[m-1][n-1] == INT_MAX ? -1 : dp[m-1][n-1];
    }
};
