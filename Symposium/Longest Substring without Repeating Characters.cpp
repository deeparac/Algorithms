class Solution {
public:
    /*
     * @param s: a string
     * @return: an integer
     */
    int lengthOfLongestSubstring(string &s) {
        // write your code here
        int rst = 0, left = 0;
        vector<int> last(256, -1);

        for (int i = 0; i < s.size(); i++) {
            if (last[s[i]] >= left) left = last[s[i]] + 1;
            last[s[i]] = i;
            rst = max(rst, i - left + 1);
        }

        return rst;
    }
};
