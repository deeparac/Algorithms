class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int rst = 0, todelete = 0;
        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); ++i) {
            ++m[s[i]];
            while (m.size() > k) {
                if (--m[s[todelete]] == 0) m.erase(s[todelete]);
                ++todelete;
            }
            rst = max(rst, i - todelete + 1);
        }
        return rst;
    }
};
