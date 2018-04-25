class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if (!root)  return 0;
        int maxSum;
        dfs(root, maxSum);
        return maxSum;
    }

    int dfs(TreeNode* root, int& maxSum) {
        if (!root)  return 0;
        int l = max(0, dfs(root->left, maxSum));
        int r = max(0, dfs(root->right, maxSum));
        maxSum = max(maxSum, l+r+root->val);
        return max(l, r) + root->val;
    }
};
