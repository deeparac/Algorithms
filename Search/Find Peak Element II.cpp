class Solution {
public:
    /*
     * @param A: An integer matrix
     * @return: The index of the peak
     */
    vector<int> findPeakII(vector<vector<int>> &A) {
        // write your code here
        vector<int> rst;
        if (A.empty()) {
            return rst;
        }

        int m = A.size();
        int n = A[0].size();

        int start = 1;
        int end = m - 2;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            int col = 0;
            int sup = A[mid][0];
            for (int i = 0; i < n; ++i) {
                if (A[mid][i] > sup) {
                    sup = A[mid][i];
                    col = i;
                }
            }

            if (A[mid + 1][col] > sup) {
                start = mid + 1;
            } else if (A[mid - 1][col] > sup) {
                end = mid - 1;
            } else {
                rst.push_back(mid);
                rst.push_back(col);
                return rst;
            }
        }

        return rst;
    }
};
