class Solution {
private:
    struct TrieNode {
        string str;
        vector<TrieNode*> children;
        TrieNode() : children(26, nullptr), str("") {}
    };

    struct Trie {
        TrieNode* root;
        Trie() : root(new TrieNode()) {}
        void insert(string s) {
            TrieNode* cur = root;
            for (int i = 0; i < s; ++i) {
                if (!cur -> children[s[i] - 'a']) {
                    cur -> children[s[i] - 'a'] = new TrieNode();
                }
                cur = cur -> children[s[i] - 'a'];
            }
            cur -> str = s;
        }
    };

    void helper(vector<vector<char>>& board,
                vector<vector<bool>>& visit,
                vector<string>& words,
                vector<string>& rst,
                TrieNode* p, int x, int y) {
        if (!p -> str.empty()) {
            rst.push_back(p -> str);
            return;
        }

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        visit[x][y] = true;
        for (int i = 0; i < 4; ++i) {
            int xs = x + dx[i];
            int ys = y + dy[i];
            if (xs >= 0 && xs < board.size() &&
                ys >= 0 && ys < board[0].size() &&
                visit[i][j] == false && p -> children[board[xs][ys] - 'a'] != nullptr) {
                helper(board, visit, words, rst, p -> children[board[i][j] - 'a'], xs, ys);
            }
        }
        visit[x][y] = false;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> rst;
        if (words.empty() || board.empty() || board[0].empty()) {
            return rst;
        }

        vector<vector<bool> > visit(board.size(), vector<bool>(board[0].size(), false));
        Trie trie;

        for (const auto& word : words) {
            trie.insert(word);
        }

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (trie.root -> children[board[i][j] - 'a'] != nullptr) {
                    helper(board, visit, words, rst, trie.root -> children[board[i][j] - 'a'], i, j);
                }
            }
        }

        return rst;
    }
};
