/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */


class Solution {
public:
    /*
     * @param A: An integer list
     * @param queries: An query list
     * @return: The result list
     */
    vector<long long> intervalSum(vector<int> &A, vector<Interval> &queries) {
        // write your code here
        vector<long long> rst;
        vector<long long> pSum(A.size() + 1, 0);
        for (int i = 1; i <= A.size(); ++i) {
            pSum[i] = pSum[i-1] + A[i-1];
        }

        for (auto& query : queries) {
            rst.push_back(pSum[query.end+1] - pSum[query.start]);
        }

        return rst;
    }
};
