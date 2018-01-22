class Solution {
public:
    /*
     * @param height: A list of integer
     * @return: The area of largest rectangle in the histogram
     */
    int largestRectangleArea(vector<int> &heights) {
        // write your code here
        stack<int> stk;
        if (heights.empty()) {
            return 0;
        }
        heights.push_back(-1);
        heights.insert(heights.begin(), -1);

        int rst = 0;
        for (int i = 0; i < heights.size(); ++i) {
            while (!stk.empty() && heights[stk.top()] > heights[i]) {
                int h = heights[stk.top()]; stk.pop();
                int w = i - stk.top() - 1;
                rst = max(rst, h * w);
            }
            stk.push(i);
        }

        return rst;
    }
};
