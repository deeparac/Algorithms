class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left(height.begin(), height.end());
        vector<int> right(height.begin(), height.end());
        int rst = 0;

        for (int i = 1; i < left.size(); ++i) {
            left[i] = max(left[i], left[i-1]);
        }
        left.insert(left.begin(), 0);
        for (int i = right.size() - 2; i >= 0; --i) {
            right[i] = max(right[i], right[i+1]);
        }
        right.push_back(0);
        for (int i = 0; i < height.size(); ++i) {
            rst += min(left[i+1], right[i]) - height[i];
        }
        return rst;
    }
};
