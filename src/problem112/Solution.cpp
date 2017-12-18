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
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root)  return false;
        int temp = 0;
        return recur(root, sum, temp);
    }

    bool recur(TreeNode* root, int& sum, int temp) {
        if (root) {
            temp += root->val;
            if (!root->left)    return recur(root->right, sum, temp);
            if (!root->right)   return recur(root->left, sum, temp);
            return recur(root->left, sum, temp) || recur(root->right, sum, temp);
        } else {
            return temp == sum;
        }
    }
};