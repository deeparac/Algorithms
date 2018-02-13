class Solution {
private:
    struct TrieNode {
        TrieNode* children[26];
        string str;
        TrieNode() {
            str = "";
            for (int i = 0; i < 26; ++i) {
                children[i] = nullptr;
            }
        }
    };

    class Trie {
    public:
        TrieNode* root;
        Trie() : root(new TrieNode()) {}
        void insert(string word) {
            TrieNode* curr = root;
            for (int i = 0; i < word.length(); ++i) {
                if (curr -> children[word[i] - 'a'] == nullptr) {
                    curr -> children[word[i] - 'a'] = new TrieNode();
                }
                curr = curr -> children[word[i] - 'a'];
            }
            curr -> str = word;
        }
    };

    void helper(vector<vector<char>>& board,
                vector<vector<bool>>& visit,
                vector<string>& rst,
                TrieNode* curr,
                int i, int j) {
        if (!(curr -> str).empty()) {
            rst.push_back(curr -> str);
            (curr -> str).clear();
        }

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        visit[i][j] = true;
        for (int k = 0; k < 4; ++k) {
            int x = i + dx[k];
            int y = j + dy[k];

            if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size() &&
                !visit[x][y] && curr -> children[board[x][y] - 'a'] != nullptr) {
                helper(board, visit, rst, curr -> children[board[x][y] - 'a'], x, y);
            }
        }
        visit[i][j] = false;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> rst;
        int m = board.size(); if (m == 0) return rst;
        int n = board[0].size(); if (n == 0) return rst;
        if (words.empty()) return rst;

        Trie trie = Trie();
        for (const auto& word : words) {
            trie.insert(word);
        }

        vector<vector<bool>> visit(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (trie.root -> children[board[i][j] - 'a'] != nullptr) {
                    helper(board, visit, rst, trie.root -> children[board[i][j] - 'a'], i, j);
                }
            }
        }

        return rst;
    }
};
