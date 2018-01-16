class Solution {
public:
    /*
     * @param A: An integer matrix
     * @return: an integer
     */
    int longestIncreasingContinuousSubsequenceII(vector<vector<int>> &A) {
        // write your code here
        m = A.size();
        if (m == 0) return 0;
        n = A[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 1));
        vector<vector<bool>> flag(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // iter through
                dp[i][j] = mSearch(A, dp, flag, i, j);
            }
        }

        int rst = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // find answer
                rst = max(rst, dp[i][j]);
            }
        }

        return rst;
    }

private:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int m;
    int n;

    int mSearch(vector<vector<int>> &A,
                 vector<vector<int>> &dp,
                 vector<vector<bool>> &flag,
                 int i,
                 int j) {
        // memory
        if (flag[i][j]) {
            return dp[i][j];
        }

        // search
        int ans = 1;
        for (int k = 0; k < 4; ++k) {
            int x = i + dx[k];
            int y = j + dy[k];

            if (x >= 0 && x < m && y >= 0 && y < n) {
                if (A[i][j] > A[x][y]) {
                    ans = max(ans, mSearch(A, dp, flag, x, y) + 1);
                }
            }
        }

        // update
        flag[i][j] = true;
        dp[i][j] = ans;
        return dp[i][j];
    }
};
