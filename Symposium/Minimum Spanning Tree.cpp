/**
 * Definition for a Connection.
 * class Connection {
 * public:
 *   string city1, city2;
 *   int cost;
 *   Connection(string& city1, string& city2, int cost) {
 *       this->city1 = city1;
 *       this->city2 = city2;
 *       this->cost = cost;
 * }
 */
class Solution {
private:
    class UFS {
    public:
        vector<int> father;
        UFS(int n) {
            for (int i = 0; i <= n; ++i) {
                father.push_back(i);
            }
        }

        int find(int x) {
            if (x == father[x]) {
                return father[x];
            }

            return father[x] = find(father[x]);
        }

        void merge(int a, int b) {
            int ra = find(a);
            int rb = find(b);

            if (ra != rb) {
                father[ra] = rb;
            }
        }
    };

    static bool cmp(Connection& lhs, Connection& rhs) {
        if (lhs.cost != rhs.cost) {
            return lhs.cost < rhs.cost;
        }

        if (lhs.city1 != rhs.city1) {
            return lhs.city1 < rhs.city1;
        }
        return lhs.city2 < rhs.city2;
    }
public:
    /**
     * @param connections given a list of connections include two cities and cost
     * @return a list of connections from results
     */
    vector<Connection> lowestCost(vector<Connection>& connections) {
        // Write your code here
        vector<Connection> rst;
        if (connections.empty()) {
            return rst;
        }

        sort(connections.begin(), connections.end(), cmp);

        unordered_map<string, int> map;
        int idx = 0;
        for (auto& connection : connections) {
            if (map.find(connection.city1) == map.end()) {
                map.insert(make_pair(connection.city1, ++idx));
            }
            if (map.find(connection.city2) == map.end()) {
                map.insert(make_pair(connection.city2, ++idx));
            }
        }

        UFS uf = UFS(idx);

        for (auto& connection : connections) {
            int c1 = map[connection.city1];
            int c2 = map[connection.city2];
            if (uf.find(c1) != uf.find(c2)) {
                uf.merge(c1, c2);
                rst.push_back(connection);
            }
        }

        if (rst.size() == idx - 1) {
            return rst;
        } else {
            return vector<Connection>();
        }
    }
};
