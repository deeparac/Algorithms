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
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    vector<Interval> merge(vector<Interval> &intervals) {
        // write your code here
        vector<Interval> rst;
        if (intervals.size() == 0) {
            return rst;
        } else if (intervals.size() == 1) {
            return intervals;
        }

        sort(intervals.begin(), intervals.end(), cmp);
        Interval newInterval = intervals[0];

        for (int i = 0; i < intervals.size() ; ++i) {
            if (intervals[i].start == newInterval.start &&
                intervals[i].end == newInterval.end) {
                continue;
            }
            if (intervals[i].start <= newInterval.end) {
                newInterval.end = max(newInterval.end, intervals[i].end);
            } else {
                rst.push_back(newInterval);
                newInterval = intervals[i];
            }
        }

        rst.push_back(newInterval);
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
