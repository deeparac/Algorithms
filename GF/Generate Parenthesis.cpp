class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> rst;
        if (n <= 0) {
            return rst;
        }

        string path = "";
        helper(rst, path, n, 0, 0);
        return rst;
    }

private:
    void helper(vector<string>& rst, string& path, int n, int i, int j) {
        if (i == n && j == n) {
            rst.push_back(path);
            return;
        }

        if (i < n) {
            path.push_back('(');
            helper(rst, path, n, i + 1, j);
            path.pop_back();
        }

        if (j < i) {
            path.push_back(')');
            helper(rst, path, n, i, j + 1);
            path.pop_back();
        }
    }
};
