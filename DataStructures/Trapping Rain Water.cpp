class Solution {
public:
    /*
     * @param heights: a list of integers
     * @return: a integer
     */
    int trapRainWater(vector<int> &heights) {
        // write your code here
        if (heights.empty()) {
            return 0;
        }

        vector<int> left(heights.size(), 0);
        vector<int> right(heights.size(), 0);
        left[0] = heights[0];
        for (int i = 1; i < left.size(); ++i) {
            left[i] = max(left[i - 1], heights[i]);
            // cout << left[i] << " ";
        }
        right[right.size() - 1] = heights.back();
        for (int i = right.size() - 2; i >= 0; --i) {
            right[i] = max(right[i + 1], heights[i]);
        }

        int rst = 0;
        for (int i = 0; i < heights.size(); ++i) {
            // cout << left[i] << " " << right[i] << endl;
            rst += min(left[i], right[i]) - heights[i];
        }

        return rst;
    }
};
