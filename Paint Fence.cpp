class Solution {
public:
    /*
     * @param n: non-negative integer, n posts
     * @param k: non-negative integer, k colors
     * @return: an integer, the total number of ways
     */
    int numWays(int n, int k) {
        // write your code here
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = k;
        dp[2] = k * k;
        for (int i = 3; i <= n; ++i) {
            dp[i] = (dp[i-1] + dp[i-2]) * (k - 1);
        }

        return dp[n];
    }
};
