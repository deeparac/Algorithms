class Solution {
public:
    /*
     * @param s: a string
     * @param p: a string
     * @return: a list of index
     */
    vector<int> findAnagrams(string &s, string &p) {
        // write your code here
        vector<int> rst;
        vector<int> map(256, 0);

        int plen = p.size();

        for (int i = 0; i < plen; ++i) {
            map[p[i]] += 1;
        }

        for (int i = 0; i < s.size(); ++i) {
            if (i < plen - 1) {
                map[s[i]] -= 1;
                continue;
            }

            map[s[i]] -= 1;

            if (checker(map)) {
                rst.push_back(i-plen+1);
            }

            map[s[i-plen+1]] +=1;
        }

        return rst;
    }

private:
    bool checker(vector<int>& map) {
        for (int i = 0; i < map.size(); ++i) {
            if (map[i] != 0) {
                return false;
            }
        }

        return true;
    }
};
