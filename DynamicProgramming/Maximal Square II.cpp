class Solution {
public:
    /*
     * @param matrix: a matrix of 0 an 1
     * @return: an integer
     */
    int maxSquare2(vector<vector<int>> &matrix) {
        // write your code here
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n));

        for (int i = 0; i < m; ++i) {
            dp[i][0] = matrix[i][0];
        }
        for (int i = 0; i < n; ++i) {
            dp[0][i] = matrix[0][i];
        }

        int rst = 1;
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 1) {
                    int clen = dp[i-1][j-1];
                    bool flag = true;
                    for (int k = 1; k <= clen; ++k) {
                        if (matrix[i][j-k] == 1) {
                            flag = false;
                            break;
                        }
                    }
                    for (int k = 1; k <= clen; ++k) {
                        if (matrix[i-k][j] == 1) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) {
                        dp[i][j] = dp[i-1][j-1] + 1;
                    } else {
                        dp[i][j] = 1;
                    }
                } else {
                    dp[i][j] = 0;
                }
                rst = max(rst, dp[i][j]);
            }
        }

        return pow(rst, 2);
    }
};
