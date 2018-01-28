class Solution {
public:
    /**
     * @param s: a string represent DNA sequences
     * @return: all the 10-letter-long sequences
     */
    vector<string> findRepeatedDna(string &s) {
        // write your code here
        vector<string> rst;
        unordered_map<string, int> map;
        string cur = "";

        if (s.size() < 10) {
            return rst;
        }

        for (int i = 0; i < 9; ++i) {
            cur += s[i];
        }

        for (int i = 9; i < s.size(); ++i) {
            cur += s[i];
            if (map.find(cur) != map.end()) {
                if (map[cur] == 1) {
                    rst.push_back(cur);
                }
                map[cur]++;
            } else {
                map[cur] = 1;
            }

            cur = cur.substr(1);
        }

        return rst;
    }
};
