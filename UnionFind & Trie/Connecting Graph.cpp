class UnionFind {
public:
    vector<int> father;
    UnionFind (int n) {
        for (int i = 0; i <= n; ++i) {
            father.push_back(i);
        }
    }

    int find(int x) {
        if (father[x] == x) {
            return x;
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

class ConnectingGraph {
public:
    UnionFind* uf;
    /*
    * @param n: An integer
    */
    ConnectingGraph(int n) {
        // do intialization if necessary
        uf = new UnionFind(n);
    }

    /*
     * @param a: An integer
     * @param b: An integer
     * @return: nothing
     */
    void connect(int a, int b) {
        // write your code here
        uf -> merge(a, b);
    }

    /*
     * @param a: An integer
     * @param b: An integer
     * @return: A boolean
     */
    bool query(int a, int b) {
        // write your code here
        int ra = uf -> find(a);
        int rb = uf -> find(b);

        return ra == rb;
    }
};
