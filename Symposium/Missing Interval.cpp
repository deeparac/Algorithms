class Solution {
public:
    /*
     * @param nums: a sorted integer array
     * @param lower: An integer
     * @param upper: An integer
     * @return: a list of its missing ranges
     */
    vector<string> findMissingRanges(vector<int> &nums, int lower, int upper) {
        // write your code here
        vector<string> rst;
        if (nums.size() == 0) {
            addRange(rst, lower, upper);
            return rst;
        }

        addRange(rst, lower, (long long)nums[0]-1);
        for (int i = 1; i < nums.size(); ++i) {
            addRange(rst, (long long)nums[i-1]+1, (long long)nums[i]-1);
        }
        addRange(rst, (long long)nums.back() + 1, upper);
        return rst;
    }

private:
    void addRange(vector<string>& rst, long long int start, long long int end) {
        if (start > end) {
            return;
        }

        if (start == end) {
            string t = to_string(start);
            rst.push_back(t);
        } else {
            string t = to_string(start) + "->" + to_string(end);
            rst.push_back(t);
        }
    }
};
