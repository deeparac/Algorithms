/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */
class UnionFind {
public:
    unordered_map<int, int> father;
    UnionFind(unordered_set<int> set) {
        for (auto s : set) {
            father[s] = s;
        }
    }

    int find(int x) {
        int parent = father[x];
        while (parent != father[parent]) {
            parent = father[parent];
        }
        int next;
        while (x != father[x]) {
            next = father[x];
            father[x] = parent;
            x = next;
        }

        return parent;
    }

    void merge(int a, int b) {
        int ra = find(a);
        int rb = find(b);
        if (ra != rb) {
            father[ra] = rb;
        }
    }
};

class Solution {
public:
    /*
     * @param nodes: a array of Directed graph node
     * @return: a connected set of a directed graph
     */
    vector<vector<int>> connectedSet2(vector<DirectedGraphNode*> nodes) {
        // write your code here
        vector<vector<int>> rst;
        if (nodes.empty()) {
            return rst;
        }

        unordered_set<int> set;
        for (auto node : nodes) {
            set.insert(node -> label);
            for (auto nb : node -> neighbors) {
                set.insert(nb -> label);
            }
        }

        UnionFind* uf = new UnionFind(set);

        for (auto node : nodes) {
            for (auto nb : node -> neighbors) {
                uf -> merge(node -> label, nb -> label);
            }
        }

        unordered_map<int, vector<int>> map;
        for (auto s : set) {
            int rs = uf -> find(s);
            if (map.find(rs) == map.end()) {
                map[rs] = vector<int>();
            }
            map[rs].push_back(s);
        }

        for (auto p : map) {
            vector<int> v = p.second;
            sort(v.begin(), v.end());
            rst.push_back(v);
        }

        return rst;
    }
};
