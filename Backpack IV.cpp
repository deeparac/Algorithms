class Solution {
public:
    /*
     * @param nums: an integer array and all positive numbers, no duplicates
     * @param target: An integer
     * @return: An integer
     */
    int backPackIV(vector<int> &nums, int m) {
        // write your code here
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                int k = 0;
                while(k * nums[i-1] <= j) {
                    dp[i][j] += dp[i-1][j-nums[i-1]*k];
                    k+=1;
                }
            }
        }

        return dp[n][m];
    }
};
