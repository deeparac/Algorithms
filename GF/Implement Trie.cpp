class Trie {
private:
    struct TrieNode {
        TrieNode* arr[26];
        bool hasWord;
        string word;

        TrieNode() : hasWord(false), word("") {
            for (int i = 0; i < 26; ++i) {
                arr[i] = nullptr;
            }
        }
    };
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* curr = root;
        for (int i = 0; i < word.length(); ++ i) {
            if (curr -> arr[word[i] - 'a'] == nullptr) {
                curr -> arr[word[i] - 'a'] = new TrieNode();
            }
            curr = curr -> arr[word[i] - 'a'];
        }
        curr -> hasWord = true;
        curr -> word = word;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* curr = root;
        for (int i = 0; i < word.length(); ++ i) {
            if (curr -> arr[word[i] - 'a'] == nullptr) {
                return false;
            }
            curr = curr -> arr[word[i] - 'a'];
        }

        return curr -> hasWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (int i = 0; i < prefix.length(); ++ i) {
            if (curr -> arr[prefix[i] - 'a'] == nullptr) {
                return false;
            }
            curr = curr -> arr[prefix[i] - 'a'];
        }

        return curr != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
