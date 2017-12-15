class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root)  return true;
        return depth(root) != -1;
    }

    int depth(TreeNode* root) {
        if (!root)  return 0;
        int left = depth(root->left);
        if (left == -1) return -1;
        int right = depth(root->right);
        if (right == -1)    return -1;
        if (abs(right - left) > 1)  return -1;
        return max(left, right) + 1;
    }
};