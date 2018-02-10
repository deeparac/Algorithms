class Solution {
public:
    bool wordBreak(string s, vector<string>& dict) {
        unordered_set<string> set(dict.begin(), dict.end());
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;
        for (int i = 1; i < dp.size(); ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (dp[j]) {
                    string str = s.substr(j, i - j);
                    if (set.find(str) != set.end()) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }

        return dp.back();
    }
};
