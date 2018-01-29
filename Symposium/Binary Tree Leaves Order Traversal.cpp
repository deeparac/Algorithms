/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


class Solution {
public:
    /*
     * @param root: the root of binary tree
     * @return: collect and remove all leaves
     */
    vector<vector<int>> findLeaves(TreeNode * root) {
        // write your code here
        vector<vector<int>> rst;
        unordered_map<int, vector<int>> map;
        solver(map, root);

        int maxDepth = 0;
        for (auto it = map.begin(); it != map.end(); ++it) {
            maxDepth = max(maxDepth, it -> first);
        }
        for (int i = 1; i <= maxDepth; ++i) {
            rst.push_back(map[i]);
        }
        return rst;
    }

private:
    int solver(unordered_map<int, vector<int>>& map, TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int height = max(
            solver(map, root -> left),
            solver(map, root -> right)
        ) + 1;
        map[height].push_back(root -> val);

        return height;
    }
};
