class Solution {
public:
    /*
     * @param n: An integer
     * @return: A boolean which equals to true if the first player will win
     */
    bool firstWillWin(int n) {
        // write your code here
        vector<int> dp(n+1, 0);
        return mSearch(dp, n);
    }

private:
    bool mSearch(vector<int> &dp, int i) {
        // cout << i << endl;
        if (dp[i] != 0) {
            if (dp[i] == 2) {
                return true;
            } else {
                return false;
            }
        }

        if (i <= 0) {
            dp[i] = 1;
        } else if (i == 1) {
            dp[i] = 2;
        } else if (i == 2) {
            dp[i] = 2;
        } else if (i == 3) {
            dp[i] = 1;
        } else {
            if ((mSearch(dp, i-2) && mSearch(dp, i-3)) ||
                (mSearch(dp, i-3) && mSearch(dp, i-4))) {
                dp[i] = 2;
            } else {
                dp[i] = 1;
            }
        }

        if (dp[i] == 2) {
            return true;
        }
        return false;
    }
};
