class UnionFind {
public:
    vector<int> father;
    UnionFind(int n) {
        for (int i = 0; i < n; ++i) {
            father.push_back(i);
        }
    }

    int find(int x) {
        if (father[x] == x) {
            return father[x];
        }

        return find(father[x]);
    }

    void merge(int a, int b) {
        int ra = find(a);
        int rb = find(b);

        if (ra != rb) {
            father[ra] = rb;
        }
    }
};
