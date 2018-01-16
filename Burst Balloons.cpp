class Solution {
public:
    /*
     * @param nums: A list of integer
     * @return: An integer, maximum coins
     */
    int maxCoins(vector<int> &nums) {
        // write your code here
        int n = nums.size();
        vector<int> arr(n + 2, 0);
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        vector<vector<int>> visited(n + 2, vector<int>(n + 2, 0));

        arr[0] = arr[n+1] = 1;
        for (int i = 1; i < n + 1; ++i) {
            arr[i] = nums[i-1];
        }

        return mSearch(arr, dp, visited, 1, n);
    }

private:
    int mSearch(vector<int>& arr,
                vector<vector<int>>& dp,
                vector<vector<int>>& visited,
                int i, int j) {
        if (visited[i][j] == 1) {
            return dp[i][j];
        }

        visited[i][j] = 1;
        int rst = 0;
        for (int k = i; k <= j; ++k) {
            int mid = arr[i-1] * arr[k] * arr[j+1];
            int left = mSearch(arr, dp, visited, i, k-1);
            int right = mSearch(arr, dp, visited, k+1, j);
            rst = max(rst, mid + left + right);
        }

        dp[i][j] = rst;
        return dp[i][j];
    }
};
