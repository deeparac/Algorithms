class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int rst = nums[0];
        int pSum = 0;

        for (int i = 0; i < nums.size(); ++i) {
            pSum += nums[i];
            rst = max(rst, pSum);
            pSum = max(pSum, 0);
        }

        return rst;
    }
};
