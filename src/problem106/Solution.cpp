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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty() || postorder.empty())   return NULL;
        int size = postorder.size();
        TreeNode* root = new TreeNode(postorder[size-1]);
        auto in_index = find(inorder.begin(), inorder.end(), postorder[size-1]);
        int left = in_index - inorder.begin();
        vector<int> left_inorder = vector<int>(inorder.begin(), inorder.begin()+left);
        vector<int> right_inorder = vector<int>(inorder.begin()+left+1, inorder.end());
        vector<int> left_postorder = vector<int>(postorder.begin(), postorder.begin()+left);
        vector<int> right_postorder = vector<int>(postorder.begin()+left, postorder.end()-1);
        root->left = buildTree(left_inorder, left_postorder);
        root->right = buildTree(right_inorder, right_postorder);
        return root;
    }
};