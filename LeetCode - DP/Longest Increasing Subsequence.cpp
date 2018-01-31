class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        vector<int> dp(nums.size(), 1);

        for (int i = 1; i < nums.size(); ++i) {
            int tmp = 0;
            for (int j = 0; j <= i; ++j) {
                if (nums[i] > nums[j]) {
                    tmp = max(tmp, dp[j]);
                }
            }
            dp[i] = max(dp[i], tmp + 1);
        }

        int rst = 0;
        for (int i = 0; i < dp.size(); ++i) {
            rst = max(rst, dp[i]);
        }

        return rst;
    }
};
