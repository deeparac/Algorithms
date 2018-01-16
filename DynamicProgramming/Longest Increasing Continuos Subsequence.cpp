class Solution {
public:
    /*
     * @param A: An array of Integer
     * @return: an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int> &A) {
        // write your code here
        if (A.size() == 0) {
            return 0;
        } else if (A.size() == 1) {
            return 1;
        }

        int len = 1;
        int rst = 0;
        for (int i = 1; i < A.size(); ++i) {
            if (A[i] > A[i-1]) {
                len += 1;
            } else {
                len = 1;
            }
            rst = max(rst, len);
        }

        len = 1;
        for (int i = A.size() - 2; i >= 0; --i) {
            if (A[i] > A[i+1]) {
                len += 1;
            } else {
                len = 1;
            }
            rst = max(rst, len);
        }

        return rst;
    }
};
