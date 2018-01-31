class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> preprocess(20001, 0);
        for (int i = 0; i < nums.size(); ++i) {
            preprocess[nums[i]] += nums[i];
        }

        vector<int> dp(20001, 0);
        dp[1] = preprocess[1];
        for (int i = 2; i < dp.size(); ++i) {
            dp[i] = max(dp[i-1], dp[i-2] + preprocess[i]);
        }

        return dp.back();
    }
};
