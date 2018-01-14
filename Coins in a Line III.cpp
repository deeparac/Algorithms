class Solution {
public:
    /*
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &vals) {
        // write your code here
        vector<vector<int>> dp(vals.size() + 1, vector<int>(vals.size() + 1));
        vector<vector<bool>> visit(vals.size() + 1, vector<bool>(vals.size() + 1, false));

        int sum = 0;
        for (auto val : vals) {
            sum += val;
        }

        return mSearch(vals, dp, visit, 0, vals.size() - 1) > sum / 2;
    }

private:
    int mSearch(vector<int> &vals,
                vector<vector<int>> &dp,
                vector<vector<bool>> &visit,
                int i,
                int j) {
        if (visit[i][j]) {
            return dp[i][j];
        }

        visit[i][j] = true;

        if (i > j) {
            dp[i][j] = 0;
        } else if (i == j) {
            dp[i][j] = vals[i];
        } else if (i + 1 == j) {
            dp[i][j] = max(vals[i], vals[j]);
        } else {
            int pick_left = min(
                mSearch(vals, dp, visit, i + 2, j),
                mSearch(vals, dp, visit, i + 1, j - 1)
            ) + vals[i];
            int pick_right = min(
                mSearch(vals, dp, visit, i, j - 2),
                mSearch(vals, dp, visit, i + 1, j - 1)
            ) + vals[j];

            dp[i][j] = max(pick_left, pick_right);
        }

        return dp[i][j];
    }
};
