class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word == "") {
            return true;
        }
        int m = board.size(); if (m == 0) return false;
        int n = board[0].size(); if (n == 0) return false;

        vector<vector<bool>> visit(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(board, visit, word, 0, i, j)) {
                    return true;
                }
            }
        }

        return false;
    }

private:
    bool dfs(vector<vector<char>>& board,
             vector<vector<bool>>& visit,
             string& word,
             int len,
             int i, int j) {
        if (len == word.size()) {
            return true;
        }

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        int m = board.size();
        int n = board[0].size();

        if (i < 0 || j < 0 || i >= m || j >= n || visit[i][j] || board[i][j] != word[len]) {
            return false;
        }

        visit[i][j] = true;
        bool rst =  dfs(board, visit, word, len + 1, i + 1, j) ||
                    dfs(board, visit, word, len + 1, i - 1, j) ||
                    dfs(board, visit, word, len + 1, i, j + 1) ||
                    dfs(board, visit, word, len + 1, i, j - 1);
        visit[i][j] = false;

        return rst;
    }
};
