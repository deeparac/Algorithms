class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()) {
            return true;
        }

        int i = 0;
        int j = s.length() - 1;
        while (i <= j) {
            bool flag = false;
            if (!checker(s[i])) {
               i++;
                flag = true;
            }

            if (!checker(s[j])) {
                j--;
                flag = true;
            }

            if (flag) {
                continue;
            }

            if (s[i] != s[j]) {
                return false;
            }

            i++;
            j--;
        }

        return true;
    }

private:
    bool checker(char& c) {
        if (c <= 'Z' && c >= 'A') {
            c += 32;
        }
        return isdigit(c) || (c <= 'z' && c >= 'a');
    }
};
