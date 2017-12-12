class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root)  return vector<int>();
        vector<int> result;
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        while (!stk.empty() || cur) {
            if (cur) {
                result.push_back(cur->val);
                stk.push(cur);
                cur = cur->left;
            } else {
                TreeNode* tmp = stk.top();
                stk.pop();
                cur = tmp->right;
            }
        }
        return result;
    }
};