class Solution {
public:
    /*
     * @param nums: A list of integers
     * @param k: An integer
     * @return: The median of the element inside the window at each moving
     */
    vector<int> medianSlidingWindow(vector<int> &nums, int k) {
        // write your code here
        vector<int> rst;
        if (k == 0) return rst;
        multiset<int> ms(nums.begin(), nums.begin() + k);
        auto mid = next(ms.begin(), (k-1) / 2);
        for (int i = k; i != nums.size() + 1; ++i) {
            rst.push_back(*mid);
            ms.insert(nums[i]);
            if (nums[i] < *mid) {
                --mid;
            }
            if (nums[i - k] <= *mid) {
                ++mid;
            }
            ms.erase(ms.lower_bound(nums[i - k]));
        }

        return rst;
    }
};
