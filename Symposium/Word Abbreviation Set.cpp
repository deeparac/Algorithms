class ValidWordAbbr {
public:
    /*
    * @param dictionary: a list of words
    */ValidWordAbbr(vector<string> dictionary) {
        // do intialization if necessary
        for (auto& word : dictionary) {
            dict[word] += 1;

            string abbr = getAbbr(word);
            map[abbr] += 1;
        }
    }

    /*
     * @param word: a string
     * @return: true if its abbreviation is unique or false
     */
    bool isUnique(string &word) {
        // write your code here
        string abbr = getAbbr(word);
        return dict[word] == map[abbr];
    }
private:
    unordered_map<string, int> dict, map;
    string getAbbr(string& word) {
        if (word.size() <= 2) {
            return word;
        }

        return word.front() + to_string(word.size() - 2) + word.back();
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param = obj.isUnique(word);
 */
