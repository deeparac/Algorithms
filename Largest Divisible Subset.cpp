class Solution {
public:
    /*
     * @param nums: a set of distinct positive integers
     * @return: the largest subset
     */
    vector<int> largestDivisibleSubset(vector<int> &nums) {
        // write your code here
        sort(nums.begin(), nums.end());

        vector<int> dp(nums.size(), 1);
        vector<int> idx(nums.size(), -1);

        int n = nums.size();
        int m = 0;
        int p = -1;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    idx[i] = j;
                }
            }

            if (dp[i] > m) {
                m = dp[i];
                p = i;
            }
        }

        vector<int> rst;
        for (int i = 0; i < m; ++i) {
            rst.push_back(nums[p]);
            p = idx[p];
        }

        return rst;
    }
};
