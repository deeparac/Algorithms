class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) {
            return vector<int>();
        }
        int n = matrix[0].size();
        vector<int> rst;

        int i = 0;
        int j = 0;
        int dir = 0;
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        while (rst.size() != m * n) {
            if (checker(matrix, i, j, dir)) {
                rst.push_back(matrix[i][j]);
                matrix[i][j] = INT_MAX;
            } else {
                i -= dx[dir % 4];
                j -= dy[dir % 4];
                ++dir;
            }

            i += dx[dir % 4];
            j += dy[dir % 4];
            cout << rst.back();
        }

        return rst;
    }

private:
    bool checker(vector<vector<int>>& matrix, int i, int j, int dir) {
        if (i < 0 || i >= matrix.size() ||
            j < 0 || j >= matrix[0].size() ||
            matrix[i][j] == INT_MAX) {
            return false;
        }

        return true;
    }
};
