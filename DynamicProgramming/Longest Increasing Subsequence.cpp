class Solution {
public:
    /*
     * @param nums: An integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> &nums) {
        // write your code here
        if (nums.size() == 0) {
            return 0;
        }

        vector<int> dp(nums.size(), 1);

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j] && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                }
            }
        }

        int rst = dp[0];

        for (int i = 1; i < dp.size(); ++i) {
            rst = max(rst, dp[i]);
        }

        return rst;
    }
};
