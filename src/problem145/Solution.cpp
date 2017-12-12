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