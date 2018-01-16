class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> A) {
        // write your code here
        if (A.empty()) {
            return 0;
        }
        int n = A.size();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));

        for (int i = 0; i <= n; ++i) {
            dp[i][0] = true;
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                dp[i][j] = dp[i-1][j];
                if (j >= A[i-1] && dp[i-1][j-A[i-1]]) {
                    dp[i][j] = true;
                }
            }
        }

        for (int j = m; j >= 0; --j) {
            if (dp[n][j]) {
                return j;
            }
        }

        return 0;
    }
};
