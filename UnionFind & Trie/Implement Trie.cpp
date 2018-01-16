class TrieNode {
public:
    TrieNode* children[26];
    bool hasWord;
    string str;

    TrieNode() {
        for (int i = 0; i < 26; ++i) {
            children[i] = NULL;
        }
        hasWord = false;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        // do intialization if necessary
        root = new TrieNode();
    }

    /*
     * @param word: a word
     * @return: nothing
     */
    void insert(string &word) {
        // write your code here
        TrieNode* p = root;
        for (int i = 0; i < word.length(); ++i) {
            if (p -> children[word[i] - 'a'] == NULL) {
                p -> children[word[i] - 'a'] = new TrieNode();
            }
            p = p -> children[word[i] - 'a'];
        }
        p -> hasWord = true;
        p -> str = word;
    }

    /*
     * @param word: A string
     * @return: if the word is in the trie.
     */
    bool search(string &word) {
        // write your code here
        TrieNode* p = root;
        for (int i = 0; i < word.size(); ++i) {
            if (p == NULL) return false;
            p = p -> children[word[i] - 'a'];
        }
        if (p == NULL || p -> hasWord == false) {
            return false;
        }

        return true;
    }

    /*
     * @param prefix: A string
     * @return: if there is any word in the trie that starts with the given prefix.
     */
    bool startsWith(string &prefix) {
        // write your code here
        TrieNode* p = root;
        for (int i = 0; i < prefix.size(); ++i) {
            p = p -> children[prefix[i] - 'a'];
            if (p == NULL) {
                return false;
            }
        }
        return true;
    }
};
