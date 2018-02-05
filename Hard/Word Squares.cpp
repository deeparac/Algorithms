class Solution {
private:
    struct TrieNode {
        vector<int> indexs;
        vector<TrieNode*> children;
        TrieNode(): children(26, nullptr) {}
    };

    TrieNode* buildTrie(const vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (int i = 0; i < words.size(); ++i) {
            TrieNode* cur = root;
            for (int j = 0; j < words[i].size(); ++j) {
                if (!cur -> children[words[i][j] - 'a']) {
                    cur -> children[words[i][j] - 'a'] = new TrieNode();
                }
                cur = cur -> children[words[i][j] - 'a'];
                cur -> indexs.push_back(i);
            }
        }
        return root;
    }

public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        vector<vector<string>> rst;
        vector<string> path(words[0].length());

        TrieNode* root = buildTrie(words);
        for (auto& word : words) {
            path[0] = word;
            helper(words, 1, root, path, rst);
        }
        return rst;
    }

    void helper(vector<string>& words, int level, TrieNode* root,
                vector<string>& path, vector<vector<string>>& rst) {
        if (level == words[0].length()) {
            rst.push_back(path);
            return;
        }

        string str = "";
        for (int i = 0; i < level; ++i) {
            str += path[i][level];
        }

        TrieNode* cur = root;
        for (int i = 0; i < str.size(); ++i) {
            if (!cur -> children[str[i] - 'a']) return;
            cur = cur -> children[str[i] - 'a'];
        }

        for (auto idx : cur -> indexs) {
            path[level] = words[idx];
            helper(words, level + 1, root, path, rst);
        }
    }
};
