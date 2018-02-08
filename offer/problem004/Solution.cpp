/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        TreeNode* root = new TreeNode(pre[0]);
        vector<int>::iterator index = find(vin.begin(), vin.end(), pre[0]);
        auto l_len = index - vin.begin();
        auto r_len = vin.end() - index - 1;
        if (l_len > 0) {
            root->left = reConstructBinaryTree(
                    vector<int>(pre.begin()+1, pre.begin()+1+l_len),
                    vector<int>(vin.begin(), vin.begin()+l_len));
        }
        if (r_len > 0) {
            root->right = reConstructBinaryTree(
                    vector<int>(pre.end()-r_len, pre.end()),
                    vector<int>(vin.end()-r_len, vin.end()));
        }
        return root;
    }
};