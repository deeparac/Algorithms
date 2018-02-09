class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.length();
        if (n == 0) {
            return s;
        }

        string t = s;
        reverse(t.begin(), t.end());

        int i;
        for (i = n; i >= 0; --i) {
            if (s.substr(0, i) == t.substr(n - i)) {
                break;
            }
        }

        return t.substr(0, n - i) + s;
    }
};
