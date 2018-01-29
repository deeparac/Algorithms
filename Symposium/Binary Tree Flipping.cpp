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
     * @return: new root
     */
    TreeNode * upsideDownBinaryTree(TreeNode * root) {
        // write your code here
        if (root == NULL) {
            return root;
        }

        solver(root);
        return rst;
    }

private:
    TreeNode* rst = NULL;
    void solver(TreeNode* root) {
        if (root -> left == NULL) {
            rst = root;
            return;
        }

        solver(root -> left);
        root -> left -> left = root -> right;
        root -> left -> right = root;
        root -> left = NULL;
        root -> right = NULL;
    }
};
