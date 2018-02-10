class Solution {
public:
    /*
     * @param grid: a boolean 2D matrix
     * @return: an integer
     */
    int numIslands(vector<vector<bool>> &grid) {
        // write your code here
        int m = grid.size();
        if (m == 0) {
            return 0;
        }
        int n = grid[0].size();
        int size = m * n;
        UnionFind uf = UnionFind(size);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    uf.island += 1;
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    if (i > 0 && grid[i-1][j]) {
                        uf.merge(i * n + j, (i-1) * n + j);
                    }
                    if (i < m - 1 && grid[i+1][j]) {
                        uf.merge(i * n + j, (i+1) * n + j);
                    }
                    if (j > 0 && grid[i][j-1]) {
                        uf.merge(i * n + j - 1, i * n + j);
                    }
                    if (j < n - 1&& grid[i][j+1]) {
                        uf.merge(i * n + j, i * n + j + 1);
                    }
                }
            }
        }

        return uf.island;
    }

private:
    class UnionFind {
    public:
        vector<int> father;
        int island;
        UnionFind(const int n) {
            for (int i = 0; i < n; ++i) {
                father.push_back(i);
            }
            island = 0;
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
                island -= 1;
            }
        }
    };
};
