/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class UnionFind {
public:
    vector<int> father;
    int island;
    UnionFind(int n) {
        island = 0;
        for (int i = 0; i < n; ++i) {
            father.push_back(-1);
        }
    }

    int find(int x) {
        if (x == father[x]) {
            return x;
        }

        return father[x] = find(father[x]);
    }

    void merge(int a, int b) {
        int ra = find(a);
        int rb = find(b);

        if (ra != rb) {
            father[ra] = rb;
            island--;
        }
    }
};

class Solution {
public:
    /*
     * @param n: An integer
     * @param m: An integer
     * @param operators: an array of point
     * @return: an integer array
     */
    vector<int> numIslands2(int n, int m, vector<Point> &operators) {
        // write your code here
        vector<int> rst;
        UnionFind* uf = new UnionFind(n * m);

        for (auto p : operators) {
            int x = p.x;
            int y = p.y;
            if (uf -> father[x * m + y] == -1) {
                uf -> island += 1;
                uf -> father[x * m + y] = x * m + y;
            }

            if (x > 0 && uf -> father[(x-1) * m + y] != -1) {
                uf -> merge(x * m + y, (x-1) * m + y);
            }
            if (x < n - 1 && uf -> father[(x+1) * m + y] != -1) {
                uf -> merge(x * m + y, (x+1) * m + y);
            }
            if (y > 0 && uf -> father[x * m + y - 1] != -1) {
                uf -> merge(x * m + y, x * m + y - 1);
            }
            if (y < m - 1 && uf -> father[x * m + y + 1] != -1) {
                uf -> merge(x * m + y, x * m + y + 1);
            }
            rst.push_back(uf -> island);
        }

        return rst;
    }
};
