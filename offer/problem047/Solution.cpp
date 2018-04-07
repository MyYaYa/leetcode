class Solution {
public:
    int TreeDepth(TreeNode* pRoot) {
        if (!pRoot) return 0;
        int maxDepth = 0;
        dfs(pRoot, 0, maxDepth);
        return maxDepth;
    }
    
    void dfs(TreeNode* pRoot, int now_depth, int& maxDepth) {
        if (!pRoot) {
            maxDepth = max(maxDepth, now_depth);
        } else {
            dfs(pRoot, now_depth + 1, maxDepth);
            dfs(pRoot, now_depth + 1, maxDepth);
        }
    }
};