class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> rst;
        int m = matrix.size(); if (m == 0) return rst;
        int n = matrix[0].size(); if (n == 0) return rst;

        vector< vector<bool> > visit(m, vector<bool>(n, false));

        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        int dir = 0;

        int i = 0;
        int j = 0;
        while (rst.size() != m * n) {
            if (i >= 0 && i < m && j >= 0 && j < n && !visit[i][j]) {
                visit[i][j] = true;
                rst.push_back(matrix[i][j]);
            } else {
                i -= dx[dir % 4];
                j -= dy[dir % 4];
                dir += 1;
            }

            i += dx[dir % 4];
            j += dy[dir % 4];
        }

        return rst;
    }
};
