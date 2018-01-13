class Solution {
public:
    /*
     * @param A: A list of integers
     * @return: An integer
     */
    int jump(vector<int> &A) {
        // write your code here
        vector<int> dp(A.size(), INT_MAX);
        dp[0] = 0;

        for (int i = 1; i < dp.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] != INT_MAX && j + A[j] >= i) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }

        return dp.back();
    }
};
