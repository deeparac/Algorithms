class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> &nums) {
        // write your code here
        if (nums.size() == 0) {
            return 0;
        }

        int sum = nums[0];
        int rst = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            sum = max(nums[i], sum + nums[i]);
            rst = max(sum, rst);
        }

        return rst;
    }
};
