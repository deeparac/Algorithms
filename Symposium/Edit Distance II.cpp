class Solution {
public:
    /*
     * @param s: a string
     * @param t: a string
     * @return: true if they are both one edit distance apart or false
     */
    bool isOneEditDistance(string &s, string &t) {
        // write your code here
        int m = s.size();
        int n = t.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for (int i = 0; i <= m; ++i) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n; ++j) {
            dp[0][j] = j;
        }


        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = min(min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1]);
                if (s[i-1] != t[j-1]) {
                    dp[i][j] += 1;
                }
            }
        }

        return dp[m][n] == 1;
    }
};
