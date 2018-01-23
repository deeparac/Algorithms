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
     * @param airplanes: An interval array
     * @return: Count of airplanes are in the sky.
     */
    int countOfAirplanes(vector<Interval> &airplanes) {
        // write your code here
        vector<pair<int, bool>> timeline;
        int rst = 0;
        int cnt = 0;

        for (auto air : airplanes) {
            timeline.push_back(make_pair(air.start, true));
            timeline.push_back(make_pair(air.end, false));
        }

        sort(timeline.begin(), timeline.end());

        for (auto t : timeline) {
            if (t.second) {
                cnt++;
            } else {
                cnt--;
            }

            rst = max(rst, cnt);
        }

        return rst;
    }
};
