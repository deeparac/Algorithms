class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        int m = A.size();
        int n = B.size();
        int len = m + n;

        if (len % 2 == 1) {
            return helper(A, B, 0, 0, len / 2 + 1);
        } else {
            return (helper(A, B, 0, 0, len / 2) + helper(A, B, 0, 0, len / 2 + 1)) / 2.0;
        }
    }

private:
    double helper(vector<int>& A, vector<int>& B, int i, int j, int k) {
        if (i >= A.size()) {
            return B[j + k - 1];
        }

        if (j >= B.size()) {
            return A[i + k - 1];
        }

        if (k == 1) {
            return min(A[i], B[j]);
        }

        int ival = i + k / 2 - 1 < A.size() ? A[i + k / 2 - 1] : INT_MAX;
        int jval = j + k / 2 - 1 < B.size() ? B[j + k / 2 - 1] : INT_MAX;

        if (ival <= jval) {
            return helper(A, B, i + k / 2, j, k - k / 2);
        } else {
            return helper(A, B, i, j + k / 2, k - k / 2);
        }
    }
};
