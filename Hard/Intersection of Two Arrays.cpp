class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> rst;
        unordered_set<int> filter;
        for (auto i : nums1) {
            filter.insert(i);
        }

        for (auto i : nums2) {
            if (filter.find(i) != filter.end()) {
                rst.insert(i);
            }
        }
        return vector<int>(rst.begin(), rst.end());
    }
};
