class Solution {
public:
    /*
     * @param triangle: a list of lists of integers
     * @return: An integer, minimum path sum
     */
    int minimumTotal(vector<vector<int>> &tri) {
        // write your code here
        int m = tri.size();

        if (m == 0) {
            return 0;
        }

        int dp[m][m];
        dp[0][0] = tri[0][0];
        for (int i = 1; i < m; ++i) {
            dp[i][0] = dp[i-1][0] + tri[i][0];
            dp[i][i] = dp[i-1][i-1] + tri[i][i];
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < i; ++j) {
                dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) + tri[i][j];
            }
        }

        int rst = INT_MAX;
        for (int i = 0; i < m; ++i) {
            rst = min(rst, dp[m-1][i]);
        }

        return rst;
    }
};
