class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& dict) {
        vector<string> rst;
        if (s == "" || dict.empty()) {
            return rst;
        }
        vector<bool> possible(s.length() + 1, true);
        string path = "";
        helper(s, dict, rst, possible, path, 0);

        return rst;
    }

private:
    void helper(string& s, vector<string>& dict, vector<string>& rst, vector<bool>& possible, string& path, int startIndex) {
        if (startIndex == s.length()) {
            rst.push_back(path.substr(0, path.length() - 1));
            return;
        }

        string word = "";
        for (int i = startIndex; i < s.length(); ++i) {
            word.push_back(s[i]);
            if (std::find(dict.begin(), dict.end(), word) != dict.end() && possible[i + 1]) {
                // cout << word << endl;
                int original_size = rst.size();
                path += word + " ";
                helper(s, dict, rst, possible, path, i + 1);
                if (original_size == rst.size()) {
                    possible[i + 1] = false;
                }
                path = path.substr(0, path.length() - word.length() - 1);
            }
        }
    }
};
