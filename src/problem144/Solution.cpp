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