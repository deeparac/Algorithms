class Solution {
public:
    /*
     * @param s1: A str
     * @param s2: Another str
     * @return: whether s2 is a scrambled str of s1
     */
    bool isScramble(string &s1, string &s2) {
        // write your code here
        if (s1.size() != s2.size()) {
            return false;
        }

        string key = s1 + " " + s2;
        if (hash.find(key) != hash.end()) {
            return hash[key];
        }

        int n = s1.size();
        if (n == 1) {
            return s1[0] == s2[0];
        }

        for (int k = 1; k < n; ++k) {
            string s1_left = s1.substr(0, k);
            string s2_left = s2.substr(0, k);
            string s1_right = s1.substr(k, n);
            string s2_right = s2.substr(k, n);
            string s2_reverseright = s2.substr(n - k, n);
            string s2_reverseleft = s2.substr(0, n - k);
            if (isScramble(s1_left, s2_left) &&
                isScramble(s1_right, s2_right) ||
                isScramble(s1_left, s2_reverseright) &&
                isScramble(s1_right, s2_reverseleft)
                ) {
                hash[key] = true;
                return true;
            }
        }
        hash[key] = false;
        return false;
    }
private:
    unordered_map<string, bool> hash;
};
