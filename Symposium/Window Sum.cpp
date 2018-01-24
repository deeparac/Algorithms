class Solution {
public:
    /*
     * @param nums: a list of integers.
     * @param k: length of window.
     * @return: the sum of the element inside the window at each moving.
     */
    vector<int> winSum(vector<int> &nums, int k) {
        // write your code here
        if (nums.empty() || k > nums.size() || k == 0) {
            return vector<int>();
        }

        vector<int> rst(nums.size() - k + 1, 0);

        int sum = 0;
        for (int i = 0; i < k; ++i) {
            sum += nums[i];
        }
        rst[0] = sum;

        for (int i = k; i < nums.size(); ++i) {
            sum += nums[i];
            sum -= nums[i-k];
            rst[i-k+1] = sum;
        }

        return rst;
    }
};
