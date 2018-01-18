class Solution {
public:
    /*
     * @param board: A list of lists of character
     * @param word: A string
     * @return: A boolean
     */
    int m, n;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    bool exist(vector<vector<char>> &board, string &word) {
        // write your code here
        if (word == "") {
            return true;
        } else if (board.empty()) {
            return false;
        }

        m = board.size();
        n = board[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0] &&
                    helper(board, visited, i, j, 0, word)) {
                        return true;
                }
            }
        }

        return false;
    }

    bool helper(vector<vector<char>> &board,
                vector<vector<bool>> &visited,
                int x, int y, int pos,
                string& word) {
        if (word[pos] == board[x][y]) {
            ++pos;
            if (pos == word.length()){
                return true;
            }
        } else {
            return false;
        }

        visited[x][y] = true;
        for (int i = 0; i < 4; ++i) {
            int xs = x + dx[i];
            int ys = y + dy[i];
            if (xs >= 0 && xs < m &&
                ys >= 0 && ys < n &&
                !visited[xs][ys] && board[xs][ys] == word[pos]) {
                if (helper(board, visited, xs, ys, pos, word)) {
                    return true;
                }
            }
        }
        visited[x][y] = false;

        return false;
    }
};
