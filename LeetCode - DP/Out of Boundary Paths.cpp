class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(N + 1, 0)));

        for (int step = 1; step <= N; ++step) {
            for (int row = 0; row < m; ++row) {
                for (int col = 0; col < n; ++col) {
                    long long v1 = (row == 0)     ? 1 : dp[row - 1][col][step - 1];
                    long long v2 = (row == m - 1) ? 1 : dp[row + 1][col][step - 1];
                    long long v3 = (col == 0)     ? 1 : dp[row][col - 1][step - 1];
                    long long v4 = (col == n - 1) ? 1 : dp[row][col + 1][step - 1];
                    dp[row][col][step] = (int)((v1 + v2 + v3 + v4) % 1000000007);
                }
            }
        }
        return dp[i][j][N];
    }
};
