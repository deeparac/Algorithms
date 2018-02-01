class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int alen = A.length();
        int blen = B.length();
        int rst = 1;
        string t = A;

        while (t.length() < B.length()) {
            t += A;
            rst += 1;
        }

        if (t.find(B) != string::npos) {
            return rst;
        }

        t += A;
        return (t.find(B) != string::npos) ? rst + 1 : -1;
    }
};
