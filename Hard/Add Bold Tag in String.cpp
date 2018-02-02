class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        const string tag = "<b>";
        const string closed = "</b>";
        vector<bool> loc(s.length(), false);

        int end = 0;
        for (int i = 0; i < s.length(); ++i) {
            for (auto word : dict) {
                int len = word.size();
                if (i + len <= s.length() && s.substr(i, len) == word) {
                    end = max(end, i + len);
                }
            }
            loc[i] = end > i;
        }

        string rst = "";
        int idx = 0;
        while (idx < s.length()) {
            if (loc[idx] == false) {
                rst += s[idx];
                idx++;
                continue;
            } else {
                rst += tag;
                while (loc[idx] == true) {
                    rst += s[idx];
                    idx++;
                }
                rst += closed;
            }
        }

        return rst;
    }
};
