class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: the median of numbers
     */
    vector<int> medianII(vector<int> &nums) {
        // write your code here
        vector<int> rst;

        for (auto n : nums) {
            addNums(n);
            rst.push_back(large.top());
        }

        return rst;
    }

private:
    priority_queue<int, vector<int>, greater<int>> small;
    priority_queue<int, vector<int>, less<int>> large;

    void addNums(int n) {
        large.push(n);
        small.push(large.top());
        large.pop();
        if (large.size() < small.size()) {
            large.push(small.top());
            small.pop();
        }
    }
};
