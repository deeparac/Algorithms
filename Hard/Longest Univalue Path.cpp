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
    int longestUnivaluePath(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int rst = INT_MIN;
        helper(root, rst);
        return rst;
    }
private:
    int helper(TreeNode* root, int& rst) {
        if (root == nullptr) {
            return 0;
        }

        int left = helper(root -> left, rst);
        int right = helper(root -> right, rst);

        int p1 = 0, p2 = 0;
        if (root -> left && root -> left -> val == root -> val) {
            p1 = left + 1;
        }
        if (root -> right && root -> right -> val == root -> val) {
            p2 = right + 1;
        }

        rst = max(rst, p1 + p2);
        return max(p1, p2);
    }
};
