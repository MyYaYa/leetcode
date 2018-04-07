class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if (!pRoot) return true;
        int num_l = IsB(pRoot->left);
        int num_r = IsB(pRoot->right);
        return abs(num_l - num_r) <= 1;
    }

    int IsB(TreeNode* root) {
        if (!root)  return 0;
        int num_l = IsB(root->left);
        int num_r = IsB(root->right);
        return (num_l > num_r) ? num_l + 1 : num_r + 1;
    }
};