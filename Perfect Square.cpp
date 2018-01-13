class Solution {
public:
    /*
     * @param n: a positive integer
     * @return: An integer
     */
    int numSquares(int n) {
        // write your code here
        vector<int> dp(n+1, INT_MAX);
        for (int i = 0; i * i <= n; ++i) {
            dp[i*i] = 1;
        }

        for (int i = 0; i <= n; ++i) {
            for (int j = 0; i + j * j <= n; ++j) {
                dp[i + j * j] = min(dp[i] + 1, dp[i + j * j]);
            }
        }

        return dp.back();
    }
};
