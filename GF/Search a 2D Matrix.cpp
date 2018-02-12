class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(); if (m == 0) return false;
        int n = matrix[0].size(); if (n == 0) return false;

        int i = m - 1;
        int j = 0;

        while (i != -1 && j != n) {
            if (matrix[i][j] > target) {
                --i;
            } else if (matrix[i][j] < target) {
                ++j;
            } else {
                return true;
            }
        }

        return false;
    }
};
