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
    int countNodes(TreeNode* root) {
        if (root==NULL) {
            return 0;
        }
        TreeNode *l=root, *r=root;
        int ln=0, rn=0;
        while (l) { l=l->left; ln++; }
        while (r) { r=r->right; rn++; }
        if (ln==rn)   return pow(2, ln)-1;
        return 1 + countNodes(root->right) + countNodes(root->left);
    }
};