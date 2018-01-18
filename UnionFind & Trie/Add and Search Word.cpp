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
        str = "";
    }
};

class WordDictionary {
public:
    /*
     * @param word: Adds a word into the data structure.
     * @return: nothing
     */
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    void addWord(string &word) {
        // write your code here
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

    /*
     * @param word: A word could contain the dot character '.' to represent any one letter.
     * @return: if the word is in the data structure.
     */
    bool search(string &word) {
        // write your code here
        int n = word.size();
        return search(word, root, n, 0);
    }

    bool search(string& word, TrieNode* p, int n, int pos) {
        if (p == NULL) {
            return false;
        }

        if (pos == n) {
            return p -> hasWord;
        }

        if (word[pos] == '.') {
            for (int i = 0; i < 26; ++i) {
                if (p -> children[i] != NULL) {
                    if (search(word, p -> children[i], n, pos + 1)) {
                        return true;
                    }
                }
            }
        } else {
            int key = word[pos] - 'a';
            if (p -> children[key] != NULL) {
                return search(word, p -> children[key], n, pos + 1);
            }
        }
        return false;
    }
};
