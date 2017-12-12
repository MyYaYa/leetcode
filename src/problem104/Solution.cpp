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
    int maxDepth(TreeNode* root) {
        if (!root)  return 0;
        int max = 0;
        int curr = 0;
        recursive(root, curr, max);
        return max;
    }

    void recursive(TreeNode* root, int curr, int& max) {
        if (root) {
            if (curr + 1 > max) max = curr + 1;
            recursive(root->left, curr+1, max);
            recursive(root->right, curr+1, max);
        }
    }
};