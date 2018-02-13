class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length()) {
            return "";
        }

        int left = 0, size = 0, mlen = s.length() + 1;
        string rst = "";
        unordered_map<char, int> map;
        for (char c : t) {
            map[c]++;
        }

        for (int right = 0; right < s.size(); ++right) {
            if (map.find(s[right]) != map.end()) {
                map[s[right]]--;
                if (map[s[right]] >= 0) {
                    size++;
                }

                while (size == t.length()) {
                    if (right - left + 1 < mlen) {
                        mlen = right - left + 1;
                        rst = s.substr(left, mlen);
                    }

                    if (map.find(s[left]) != map.end()) {
                        map[s[left]]++;
                        if (map[s[left]] > 0) {
                            size--;
                        }
                    }
                    ++left;
                }
            }
        }

        return rst;
    }
};
