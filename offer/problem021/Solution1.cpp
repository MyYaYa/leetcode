class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if (!pRoot) return;
        stack<TreeNode*> stk;
        stk.push(pRoot);
        while (!stk.empty()) {
            TreeNode* top = stk.top();
            stk.pop();
            if (top->right || top->left) {
                TreeNode* tmp = top->right;
                top->right = top->left;
                top->left = tmp;
            }
            if (top->right)
                stk.push(top->right);
            if (top->left)
                stk.push(top->left);
        }
    }
};