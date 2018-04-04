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

class Solution1 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root)  return vector<int>();
        vector<int> result;
        preOrder(root, result);
        return result;
    }
    
    void preOrder(TreeNode* root, vector<int>& result) {
        if (root) {
            result.push_back(root->val);
            preOrder(root->left, result);
            preOrder(root->right, result);
        } else
            return;
    }
};