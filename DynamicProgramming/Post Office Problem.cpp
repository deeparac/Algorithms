class Solution {
public:
    /*
     * @param A: an integer array
     * @param k: An integer
     * @return: an integer
     */
    int postOffice(vector<int> &A, int k) {
        // write your code here
        if (A.empty() || k <= 0 || k > A.size()) {
            return 0;
        }

        sort(A.begin(), A.end());
        int n = A.size();
        vector<vector<int>> distance(n+1, vector<int>(n+1, 0));
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; ++j) {
                int mid = i + (j - i) / 2;
                for (int k = i; k <= j; ++k) {
                    distance[i][j] += abs(A[k-1] - A[mid-1]);
                }
            }
        }

        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for (int i = 0; i <= n; ++i) {
            dp[i][1] = distance[1][i];
        }

        for(int l = 2; l <= k; l++){
            for(int i = l; i <= n; i++){
                dp[i][l] = INT_MAX;
                for(int j = l - 1; j < i; j++){
                    dp[i][l] = min(dp[i][l], dp[j][l - 1] + distance[j + 1][i]);
                }
            }
        }

        return dp[n][k];
    }
};
