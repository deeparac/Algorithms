class Solution {
public:
    /*
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &vals) {
        // write your code here
        int sum = 0;
        for (auto val : vals) {
            sum += val;
        }

        vector<int> dp(vals.size() + 1, 0);
        vector<bool> visit(vals.size() + 1, false);
        return mSearch(vals, dp, visit, vals.size()) * 2 > sum;
    }

private:
    int mSearch(vector<int> &vals,
                vector<int> &dp,
                vector<bool> &visit,
                int i) {
        if (visit[i]) {
            return dp[i];
        }

        visit[i] = true;
        int n = vals.size();

        if (i <= 0) {
            dp[i] = 0;
        } else if (i == 1) {
            dp[i] = vals[n - 1];
        } else if (i == 2) {
            dp[i] = vals[n - 1] + vals[n - 2];
        } else if (i == 3) {
            dp[i] = vals[n - 2] + vals[n - 3];
        } else {
            dp[i] = max(
                min(
                    mSearch(vals, dp, visit, i - 2),
                    mSearch(vals, dp, visit, i - 3)
                ) + vals[n - i],
                min(
                    mSearch(vals, dp, visit, i - 3),
                    mSearch(vals, dp, visit, i - 4)
                ) + vals[n - i] + vals[n - i + 1]
            );
        }

        return dp[i];
    }
};
