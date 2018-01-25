class Solution {
public:
    /*
     * @param word: a non-empty string
     * @param abbr: an abbreviation
     * @return: true if string matches with the given abbr or false
     */
    bool validWordAbbreviation(string word, string abbr) {
        // write your code here
        int i = 0;
        int j = 0;

        while (i < word.size() && j < abbr.size()) {
            int val = 0;
            if (j < abbr.size() && abbr[j] == '0') {
                return false;
            }

            while (j < abbr.size() && isdigit(abbr[j])) {
                val = val * 10 + abbr[j] - '0';
                j += 1;
            }

            i += val;
            if (i < word.size() && abbr[j++] != word[i++]) {
                return false;
            } else if (i > word.size()) {
                return false;
            }
        }

        return true;
    }
};
