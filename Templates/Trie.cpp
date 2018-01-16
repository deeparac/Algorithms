class TrieNode {
public:
    TrieNode* children[26];
    bool hasWord;
    string str;

    TrieNode() {
        for (int i = 0; i < 256; ++i) {
            children[i] = NULL;
        }
        hasWord = false;
    }

    static void addWord(TrieNode* root, string& word) {
        TrieNode* p = root;
        for (int i = 0; i < word.size(); ++i) {
            if (p -> children[word[i] - 'a'] == NULL) {
                p -> children[word[i] - 'a'] = new TrieNode();
            }
            p = p -> children[word[i] - 'a'];
        }
        p -> hasWord = true;
        p -> str = word;
    }
};
