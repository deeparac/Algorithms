class Solution {
public:
    /*
     * @param numCourses: a total of n courses
     * @param prerequisites: a list of prerequisite pairs
     * @return: the course order
     */
    vector<int> findOrder(int numCourses, vector<pair<int, int>> &prerequisites) {
        // write your code here
        vector<int> rst;
        vector<int> degree(numCourses); // count nums of prerequisites
        vector<vector<int>> map(numCourses, vector<int>()); // store prerequisites

        for (auto& p : prerequisites) {
            degree[p.first]++;
            map[p.second].push_back(p.first);
        }

        queue<int> q;
        for (int i = 0; i < degree.size(); ++i) {
            if (degree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int course = q.front(); q.pop();
            rst.push_back(course);
            for (auto& v : map[course]) {
                degree[v]--;
                if (degree[v] == 0) {
                    q.push(v);
                }
            }
        }

        if (rst.size() == numCourses) {
            return rst;
        }

        return vector<int>();
    }
};
