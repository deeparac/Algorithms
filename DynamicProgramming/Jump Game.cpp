class Solution {
public:
    /*
     * @param A: A list of integers
     * @return: A boolean
     */
    bool canJump(vector<int> &A) {
        // write your code here
        if (A.size() == 0) {
            return false;
        }

        vector<bool> dp(A.size(), false);
        dp[0] = true;

        for (int i = 0; i < dp.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] == true && j + A[j] >= i) {
                    dp[i] = true;
                }
            }
        }

        return dp.back();
    }
};
