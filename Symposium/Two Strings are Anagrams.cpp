class Solution {
public:
    /**
     * @param s: The first string
     * @param b: The second string
     * @return true or false
     */
    bool anagram(string s, string t) {
        // write your code here
        if (s.size() != t.size()) {
            return false;
        }

        vector<int> map(26, 0);

        for (int i = 0; i < s.size(); ++i) {
            map[s[i] - 'a']++;
            map[t[i] - 'a']--;
        }

        for (int i = 0; i < map.size(); ++i) {
            if (map[i] != 0) {
                return false;
            }
        }

        return true;
    }
};
