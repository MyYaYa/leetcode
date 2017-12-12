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