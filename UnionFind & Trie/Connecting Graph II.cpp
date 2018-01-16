class ConnectingGraph2 {
public:
    vector<int> father;
    vector<int> nums;
    /*
    * @param n: An integer
    */
    ConnectingGraph2(int n) {
        // do intialization if necessary
        for (int i = 0; i <= n; ++i) {
            father.push_back(i);
            nums.push_back(1);
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
            nums[rb] += nums[ra];
        }
    }

    /*
     * @param a: An integer
     * @return: An integer
     */
    int query(int a) {
        // write your code here
        int ra = find(a);
        return nums[ra];
    }
};
