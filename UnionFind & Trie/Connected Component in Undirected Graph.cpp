/**
 * Definition for Undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class UnionFind {
public:
    unordered_map<int, int> father;
    UnionFind(unordered_set<int> nodes) {
        for (auto node : nodes) {
            father[node] = node;
        }
    }

    int find(int x) {
        int parent = father[x];
        while (parent != father[parent]) {
            parent = father[parent];
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
     * @param nodes: a array of Undirected graph node
     * @return: a connected set of a Undirected graph
     */
    UnionFind* uf;
    vector<vector<int>> connectedSet(vector<UndirectedGraphNode*> nodes) {
        // write your code here
        vector<vector<int>> rst;
        unordered_set<int> set;
        unordered_map<int, vector<int>> map;
        if (nodes.empty()) {
            return rst;
        }

        for (auto node : nodes) {
            set.insert(node -> label);
            for (auto nb : node -> neighbors) {
               set.insert(nb -> label);
            }
        }

        uf = new UnionFind(set);

        for (auto node : nodes) {
            for (auto nb : node -> neighbors) {
                int nl = uf -> find(node -> label);
                int nbl = uf -> find(nb -> label);
                if (nl != nbl) {
                    uf -> merge(nl, nbl);
                }
            }
        }

        for (auto p : set) {
            int rp = uf -> find(p);

            if (map.find(rp) == map.end()) {
                map[rp] = vector<int>();
            }

            map[rp].push_back(p);
        }

        for (auto p : map) {
            vector<int> vec = p.second;
            sort(vec.begin(), vec.end());
            rst.push_back(vec);
        }

        return rst;
    }
};
