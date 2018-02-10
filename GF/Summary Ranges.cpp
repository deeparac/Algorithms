class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> rst;
        if (nums.empty()) {
            return rst;
        }

        string path;
        int start = nums[0];
        int end = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (end + 1 != nums[i]) {
                if (start == end) {
                    path = to_string(start);
                } else {
                    path = to_string(start) + "->" + to_string(end);
                }
                rst.push_back(path);
                start = end = nums[i];
            } else {
                end += 1;
            }
        }

        if (start == end) {
            path = to_string(start);
        } else {
            path = to_string(start) + "->" + to_string(end);
        }
        rst.push_back(path);

        return rst;
    }
};
