/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return vector<TreeNode*>();
        }

        return solver(1, n);
    }

private:
    vector<TreeNode*> solver(int min, int max) {
        vector<TreeNode*> rst;
        if (min > max) {
            return rst;
        }

        for (int i = min; i <= max; ++i) {
            vector<TreeNode*> left = solver(min, i - 1);
            vector<TreeNode*> right = solver(i + 1, max);

            for (int j = 0; j < left.size(); ++j) {
                for (int k = 0; k < right.size(); ++k) {
                    TreeNode * root = new TreeNode(i); // cur
                    root -> left = left[j];
                    root -> right = right[k];
                    rst.push_back(root);
                }
            }
        }

        return rst;
    }
};
