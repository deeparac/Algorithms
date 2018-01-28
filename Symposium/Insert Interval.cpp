/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */


class Solution {
public:
    /*
     * @param intervals: Sorted interval list.
     * @param newInterval: new interval.
     * @return: A new interval list.
     */
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // write your code here
        if (intervals.empty()) {
            vector<Interval> ret;
            ret.push_back(newInterval);
            return ret;
        }
        vector<Interval> copyIntervals = intervals;
        copyIntervals.push_back(newInterval);
        sort(copyIntervals.begin(), copyIntervals.end(), cmp);

        Interval minions = copyIntervals[0];
        vector<Interval> ret;
        for (int i = 0; i < copyIntervals.size(); ++i) {
            if (minions.start == copyIntervals[i].start &&
                minions.end == copyIntervals[i].end) {
                    continue;
            }

            if (minions.end >= copyIntervals[i].start) {
                minions.end = max(minions.end, copyIntervals[i].end);
            } else {
                ret.push_back(minions);
                minions = copyIntervals[i];
            }
        }
        ret.push_back(minions);
        return ret;
    }

private:
    static bool cmp(const Interval& lhs, const Interval& rhs) {
        return lhs.start < rhs.start;
    }
};
