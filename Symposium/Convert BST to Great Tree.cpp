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
     * @return: the new root
     */
    TreeNode * convertBST(TreeNode * root) {
        // write your code here
        sum = 0;
        solver(root);
        return root;
    }

private:
    int sum;
    void solver(TreeNode* root) {
        if (root == NULL) {
            return;
        }

        solver(root -> right);
        sum += root -> val;
        root -> val = sum;
        solver(root -> left);
    }
};
