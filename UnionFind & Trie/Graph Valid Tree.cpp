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
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>> &edges) {
        // write your code here
        if (n - 1 != edges.size()) {
            return false;
        }

        unordered_set<int> set;
        for (auto v : edges) {
            set.insert(v[0]);
            set.insert(v[1]);
        }

        UnionFind uf = UnionFind(set);

        for (auto e : edges) {
            if (uf.find(e[0]) == uf.find(e[1])) {
                return false;
            }
            uf.merge(e[0], e[1]);
        }

        return true;
    }
};
