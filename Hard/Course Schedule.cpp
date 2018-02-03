class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> numPres(numCourses, 0);
        unordered_map<int, vector<int>> map;

        for (const auto& p : prerequisites) {
            numPres[p.first] += 1;
            map[p.second].push_back(p.first);
        }

        queue<int> q;
        for (int i = 0; i < numPres.size(); ++i) {
            if (numPres[i] == 0) {
                q.push(i);
            }
        }

        int taken = 0;
        while (!q.empty()) {
            int course = q.front(); q.pop();
            taken += 1;
            for (auto& list : map[course]) {
                numPres[list] -= 1;
                if (numPres[list] == 0) {
                    q.push(list);
                }
            }
        }

        return taken == numCourses;
    }
};
