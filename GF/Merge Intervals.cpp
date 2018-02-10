/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> rst;
        if (intervals.empty()) {
            return rst;
        }
        sort(intervals.begin(), intervals.end(), cmp);

        Interval cur = intervals[0];
        for (int i = 1; i < intervals.size(); ++i) {
            if (cur.end < intervals[i].start) {
                rst.push_back(cur);
                cur = intervals[i];
            } else {
                cur.end = max(cur.end, intervals[i].end);
            }
        }

        rst.push_back(cur);
        return rst;
    }

private:
    static bool cmp(const Interval& lhs, const Interval& rhs) {
        if (lhs.start != rhs.start) {
            return lhs.start < rhs.start;
        } else {
            return lhs.end > rhs.end;
        }
    }
};
