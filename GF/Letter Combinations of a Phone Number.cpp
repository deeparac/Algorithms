class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> rst;
        if (digits.empty()) {
            return rst;
        }

        string path = "";
        helper(digits, path, mapping, rst, 0);
        return rst;
    }

private:
    void helper(string& digits,
                string& path,
                vector<string>& mapping,
                vector<string>& rst,
                int pos) {
        if (path.length() == digits.length()) {
            rst.push_back(path);
            return;
        }

        string candidates = mapping[digits[pos] - '0'];
        for (const auto candidate : candidates) {
            path.push_back(candidate);
            helper(digits, path, mapping, rst, pos + 1);
            path.pop_back();
        }
    }
};
