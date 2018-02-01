class Solution {
public:
    string nextClosestTime(string time) {
        vector<int> d = {
            time[0] - '0', time[1] - '0', time[3] - '0', time[4] - '0' };

        int h = d[0] * 10 + d[1];
        int m = d[2] * 10 + d[3];
        vector<int> curr(4, 0);
        int now = toTime(h, m);
        int best = now;

        dfs(0, d, curr, now, best);
        char buff[5];
        sprintf(buff, "%02d:%02d", best / 60, best % 60);
        return string(buff);
    }
private:
    void dfs(int dep, const vector<int>& digits, vector<int>& curr, int time, int& best) {
        if (dep == 4) {
            int curr_h = curr[0] * 10 + curr[1];
            int curr_m = curr[2] * 10 + curr[3];
            if (curr_h > 23 || curr_m > 59) return;
            int curr_time = toTime(curr_h, curr_m);
            if (timeDiff(time, curr_time) < timeDiff(time, best))
                best = curr_time;
            return;
        }

        for (int digit : digits) {
            curr[dep] = digit;
            dfs(dep + 1, digits, curr, time, best);
        }
    }

    int toTime(int h, int m) {
        return h * 60 + m;
    }

    int timeDiff(int t1, int t2) {
        if (t1 == t2) return INT_MAX;
        return ((t2 - t1) + 24 * 60) % (24 * 60);
    }
};
