class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int slen = s.length();
        int tlen = t.length();

        if (slen > tlen) {
            return isOneEditDistance(t, s);
        }

        if (abs(slen - tlen) > 1) {
            return false;
        }

        if (slen == tlen) {
            int i = 0, j = 0;
            int cnt = 0;
            while (i < slen && j < tlen) {
                if (s[i] != t[i]) {
                    cnt++;
                }
                i++;
                j++;
            }
            if (cnt != 1) {
                return false;
            }
        }

        if (tlen - slen == 1) {
            int i = 0, j = 0;
            int cnt = 0;
            while (i < slen && j < tlen) {
                if (s[i] != t[j]) {
                    j++;
                    cnt++;
                    continue;
                }
                i++;
                j++;
            }
            if (cnt > 1) {
                return false;
            }
        }

        return true;
    }
};
