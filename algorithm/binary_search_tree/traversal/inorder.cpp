class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode *> stack;
        TreeNode *cur = root;
        while(!stack.empty() || cur) {
            if (cur) {
                stack.push(cur);
                cur = cur->left;
            } else {
                TreeNode *node = stack.top();
                result.push_back(node->val);
                stack.pop();
                cur = node->right;
            }
        }
        return result;
    }
};

class Solution1 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root)  return vector<int>();
        vector<int> result;
        inOrder(root, result);
        return result;
    }

    void inOrder(TreeNode* root, vector<int>& result) {
        if (!root)  return;
        inOrder(root->left, result);
        result.push_back(root->val);
        inOrder(root->right, result);
    }
};