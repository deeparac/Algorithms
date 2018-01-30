class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> dp(26, 0);

        int len = 0;
        for (int i = 0; i < p.size(); ++i) {
            if (i > 0 && (p[i] - 1 == p[i-1] || p[i] == 'a' && p[i-1] == 'z')) {
                len += 1;
            } else {
                len = 1;
            }

            dp[p[i] - 'a'] = max(dp[p[i] - 'a'], len);
        }

        int rst = 0;
        for (int i : dp) {
            rst += i;
        }

        return rst;
    }
};
