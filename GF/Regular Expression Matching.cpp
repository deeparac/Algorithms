class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        vector< vector<bool> > dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] != '.' && p[j - 1] != '*') {
                    if (i > 0 && s[i - 1] == p[j - 1] && dp[i - 1][j - 1])
                        dp[i][j] = true;
                } else if (p[j-1]=='.') {
                    if (i > 0 && dp[i - 1][j - 1])
                        dp[i][j] = true;
                } else if (j > 1) {
                    if (dp[i][j - 1] || dp[i][j - 2]) {
                        dp[i][j] = true;
                    } else if (i > 0 && (p[j - 2] == s[i - 1] || p[j - 2] == '.') && dp[i - 1][j]) {
                        dp[i][j] = true;
                    }
                }
            }
        }

        return dp[m][n];
    }
};
