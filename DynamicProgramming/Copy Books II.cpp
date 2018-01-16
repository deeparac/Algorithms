class Solution {
public:
    /*
     * @param n: An integer
     * @param times: an array of integers
     * @return: an integer
     */
    int copyBooksII(int n, vector<int> &times) {
        // write your code here
        vector<vector<int>> dp(times.size(), vector<int>(n+1));

        for (int j = 0; j <= n; ++j) {
            dp[0][j] = j * times[0];
        }

        for (int i = 1; i < times.size(); ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = INT_MAX;
                for (int l = 0; l <= j; ++l) {
                    dp[i][j] = min(dp[i][j], max(dp[i-1][j-l], times[i] * l));
                    if (dp[i-1][j-l] <= times[i] * l) {
                        break;
                    }
                }
            }
        }

        return dp[dp.size()-1][n];
    }
};
