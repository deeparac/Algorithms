class Solution {
public:
    /*
     * @param costs: n x 3 cost matrix
     * @return: An integer, the minimum cost to paint all houses
     */
    int minCost(vector<vector<int>> &costs) {
        // write your code here
        vector<vector<int>> dp(costs.size() + 1, vector<int>(3, 0));
        dp[0][0] = 0;
        dp[0][1] = 0;
        dp[0][2] = 0;
        for (int i = 1; i < dp.size(); ++i) {
            dp[i][0] = costs[i-1][0] + min(dp[i-1][1], dp[i-1][2]);
            dp[i][1] = costs[i-1][1] + min(dp[i-1][0], dp[i-1][2]);
            dp[i][2] = costs[i-1][2] + min(dp[i-1][1], dp[i-1][0]);
        }

        int n = dp.size() - 1;
        return min(min(dp[n][0], dp[n][1]), dp[n][2]);
    }
};
