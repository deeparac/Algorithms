class Solution {
public:
    /*
     * @param s: a string
     * @param t: a string
     * @return: true if the characters in s can be replaced to get t or false
     */
    bool isIsomorphic(string s, string t) {
        // write your code here
        vector<int> map(256, 0);
        for (int i = 0; i < s.size(); i++) {
            if (map[s[i]] == 0) {
                map[s[i]] = t[i];
            } else {
                if (map[s[i]] != t[i]) {
                    return false;
                }
            }
        }

        vector<int> map2(256, 0);
        for (int i = 0; i < t.size(); i++) {
            if (map2[t[i]] == 0) {
                map2[t[i]] = s[i];
            } else {
                if (map2[t[i]] != s[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};
