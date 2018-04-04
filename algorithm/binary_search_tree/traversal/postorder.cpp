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

class Solution1 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root)  return vector<int>();
        vector<int> result;
        postOrder(root, result);
        return result;
    }
    
    void postOrder(TreeNode* root, vector<int>& result) {
        if (root) {
            postOrder(root->left, result);
            postOrder(root->right, result);
            result.push_back(root->val);
        }
    }
};