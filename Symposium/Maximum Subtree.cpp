class Solution {
public:
    /*
     * @param root: the root of binary tree
     * @return: the maximum weight node
     */
    int sum;
    TreeNode* rst;

    TreeNode * findSubtree(TreeNode * root) {
        // write your code heres
        sum = 0;
        rst = NULL;
        helper(root);
        return rst;
    }

    int helper(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int left = helper(root -> left);
        int right = helper(root -> right);

        int s = left + right + root -> val;
        if (s > sum) {
            sum = s;
            rst = root;
        }

        return s;
    }
};
