class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        TreeNode* lastNode = NULL;
        while (!stk.empty() || cur) {
            if (cur) {
                stk.push(cur);
                cur = cur->left;
            } else {
                TreeNode* tmp = stk.top();
                if (tmp->right && tmp->right != lastNode) {
                    cur = tmp->right;
                } else {
                    result.push_back(tmp->val);
                    lastNode = tmp;
                    stk.pop();
                }
            }
        }
        return result;
    }
};