class Solution {
public:
    /*
     * @param matrix: a matrix of 0 and 1
     * @return: an integer
     */
    int maxSquare(vector<vector<int>>& matrix) {
        // write your code here
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        if (n == 0) return 0;

        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; ++i) {
            dp[i][0] = matrix[i][0];
        }
        for (int j = 0; j < n; ++j) {
            dp[0][j] = matrix[0][j];
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 1) {
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]);
                    dp[i][j] += 1;
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        int rst = INT_MIN;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rst = max(rst, dp[i][j]);
            }
        }

        return pow(rst, 2);
    }
};
