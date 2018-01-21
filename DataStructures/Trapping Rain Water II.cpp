class Solution {
public:
    /*
     * @param heights: a matrix of integers
     * @return: an integer
     */
    int trapRainWater(vector<vector<int>> &heights) {
        // write your code here
        int m = heights.size(); if (m == 0) return 0;
        int n = heights[0].size(); if (n == 0) return 0;
        int sl = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    q.push({heights[i][j], i * n + j});
                    visited[i][j] = 1;
                }
            }
        }

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        int rst = 0;

        while (!q.empty()) {
            auto p = q.top(); q.pop();
            int l = p.first;
            int r = p.second / n;
            int c = p.second % n;
            sl = max(sl, l);
            for (int i = 0; i < 4; ++i) {
                int x = r + dx[i];
                int y = c + dy[i];
                if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] == 1) {
                    continue;
                }

                visited[x][y] = 1;
                if (heights[x][y] < sl) {
                    rst += sl - heights[x][y];
                }
                q.push({heights[x][y], x * n + y});
            }
        }

        return rst;
    }
};
