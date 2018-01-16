class Solution {
public:
    /*
     * @param A: An array of non-negative integers
     * @return: The maximum amount of money you can rob tonight
     */
    long long houseRobber(vector<int> &A) {
        // write your code here
        if (A.size() == 0) {
            return 0;
        } else if (A.size() == 1) {
            return A[0];
        }

        vector<long long> dp(A.size() + 1, 0);
        dp[0] = 0;
        dp[1] = A[0];

        for (int i = 2; i < A.size() + 1; ++i) {
            dp[i%2] = max(dp[(i-1)%2], dp[(i-2)%2] + A[i-1]);
        }

        return dp[A.size()%2];
    }
};
