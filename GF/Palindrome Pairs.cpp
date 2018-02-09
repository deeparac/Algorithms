class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        unordered_map<string, int> m;
        for (int i = 0; i < words.size(); ++i) m[words[i]] = i;
        for (int i = 0; i < words.size(); ++i) {
            int l = 0, r = 0;
            while (l <= r) {
                string t = words[i].substr(l, r - l);
                reverse(t.begin(), t.end());
                if (m.count(t) && i != m[t] && isValid(words[i].substr(l == 0 ? r : 0, l == 0 ? words[i].size() - r: l))) {
                    if (l == 0) res.push_back({i, m[t]});
                    else res.push_back({m[t], i});
                }
                if (r < words[i].size()) ++r;
                else ++l;
            }
        }
        return res;
    }

    bool isValid(string t) {
        for (int i = 0; i < t.size() / 2; ++i) {
            if (t[i] != t[t.size() - 1 - i]) return false;
        }
        return true;
    }
};
