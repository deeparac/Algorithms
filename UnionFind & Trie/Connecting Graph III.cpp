class ConnectingGraph3 {
public:
    vector<int> father;
    int parts;
    /*
    * @param n: An integer
    */ConnectingGraph3(int n) {
        // do intialization if necessary
        parts = n;
        for (int i = 0; i <= n; ++i) {
            father.push_back(i);
        }
    }

    int find(int x) {
        if (x == father[x]) {
            return x;
        }

        return father[x] = find(father[x]);
    }

    /*
     * @param a: An integer
     * @param b: An integer
     * @return: nothing
     */
    void connect(int a, int b) {
        // write your code here
        int ra = find(a);
        int rb = find(b);

        if (ra != rb) {
            father[ra] = rb;
            parts -= 1;
        }
    }

    /*
     * @return: An integer
     */
    int query() {
        // write your code here
        return parts;
    }
};
