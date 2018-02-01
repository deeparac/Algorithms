class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string ss;
        for (int i = S.length() - 1; i >= 0; --i) {
            if (S[i] == '-') {
                continue;
            }
            if (isdigit(S[i])) {
                ss += S[i];
            } else {
                if (S[i] >= 'a' && S[i] <= 'z') {
                    ss += S[i] - 32;
                } else {
                    ss += S[i];
                }
            }
        }

        int extra = 0;
        for (int i = 0; i < ss.length(); ++i) {
            if (i != 0 && (i - extra) % K == 0) {
                ss.insert(ss.begin() + i, '-');
                ++i;
                ++extra;
            }
        }
        reverse(ss.begin(), ss.end());
        return ss;
    }
};
