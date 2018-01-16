class Solution {
public:
    /*
     * @param A: An integer array
     * @return: An integer
     */
    int stoneGame(vector<int> &A) {
        // write your code here
        if (A.empty()) {
            return 0;
        }
        int len = A.size();

        vector<vector<int>> dp(len, vector<int>(len));
        vector<vector<int>> sum(len, vector<int>(len));
        vector<vector<int>> visited(len, vector<int>(len));

        for (int i = 0; i < len; ++i) {
            sum[i][i] = A[i];
            for (int j = i + 1; j < len; ++j) {
                sum[i][j] = sum[i][j-1] + A[j];
            }
        }

        for (int i = 0; i < len; i++) {
            dp[i][i] = 0;
        }

        return mSearch(0, len - 1, dp, sum, visited);
    }

    int mSearch(int i, int j,
                vector<vector<int>>& dp,
                vector<vector<int>>& sum,
                vector<vector<int>>& visited) {

        if (visited[i][j] == 1) {
            return dp[i][j];
        }

        if (i == j) {
            visited[i][j] = 1;
            return dp[i][j];
        }

        dp[i][j] = INT_MAX;
        for (int k = i; k < j; k++) {
            dp[i][j] = min(
                dp[i][j],
                mSearch(i, k, dp, sum, visited) +
                mSearch(k + 1, j, dp, sum, visited) +
                sum[i][j]
            );
        }

        visited[i][j] = 1;
        return dp[i][j];
    }
};
