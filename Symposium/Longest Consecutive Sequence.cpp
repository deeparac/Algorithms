class Solution {
public:
    /*
     * @param num: A list of integers
     * @return: An integer
     */
    int longestConsecutive(vector<int> &num) {
        // write your code here
        sort(num.begin(), num.end());
        int rst = 0;
        int cur = 1;
        for (int i = 1; i < num.size(); ++i) {
            if (num[i-1] == num[i]) {
                continue;
            }
            if (num[i] - 1 == num[i-1]) {
                cur++;
            } else {
                rst = max(cur, rst);
                cur = 1;
            }
        }
        rst = max(cur, rst);
        return rst;
    }
};
