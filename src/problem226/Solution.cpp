class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root)  return root;
        TreeNode* tmp = invertTree(root->right);
        root->right = invertTree(root->left);
        root->left = tmp;
        return root;
    }
};