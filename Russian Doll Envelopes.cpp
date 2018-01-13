class Solution {
public:
    /*
     * @param envelopes: a number of envelopes with widths and heights
     * @return: the maximum number of envelopes
     */
    int maxEnvelopes(vector<pair<int, int>>& envs) {
        // write your code here
        sort(envs.begin(), envs.end(), [](const pair<int, int> &a, const pair<int, int> &b){
            if (a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        });

        vector<int> dp(envs.size(), 1);

        for (int i = 0; i < dp.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if ((envs[i].first > envs[j].first) &&
                  (envs[i].second > envs[j].second)) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        int rst = 0;
        for (int i = 0; i < dp.size(); ++i) {
            rst = max(rst, dp[i]);
        }

        return rst;
    }
};
