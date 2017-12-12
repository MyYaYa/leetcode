/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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