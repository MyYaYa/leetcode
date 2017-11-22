class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (root==NULL || (root->left==NULL && root->right==NULL))
            return true;
        return func(root, LLONG_MIN, LLONG_MAX);
    }
    bool func(TreeNode* node, long long low, long long high) {
        if (node == NULL)
            return true;
        if (node->val <= low || node->val >= high) {
            return false;
        } else {
            return func(node->left, low, node->val) && func(node->right, node->val, high);
        }
    }
};