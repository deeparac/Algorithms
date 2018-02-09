class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> rst(nums.size());
        vector<int> helper;
        if (nums.empty()) {
            return rst;
        }

        // multiset TLE
        // 5, 2, 6, 1
        // 2, 1, 1, 0
        for (int i = nums.size() - 1; i >= 0; --i) {
            const auto it = lower_bound(helper.begin(), helper.end(), nums[i]);
            int dis = it - helper.begin();
            rst[i] = dis;
            helper.insert(it, nums[i]);
        }

        return rst;
    }
};
