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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        if (!root)  return result;
        vector<int> temp;
        int sum_t = 0;
        recur(root, sum, sum_t, temp, result);
        return result;
    }

    void recur(TreeNode* root, int& sum, int sum_t, vector<int>& temp, vector<vector<int>>& result) {
        if (root) {
            sum_t += root->val;
            temp.push_back(root->val);
            if (root->left==NULL && root->right==NULL) {
                if (sum_t == sum)
                    result.push_back(temp);
                temp.pop_back();
            } else {
                recur(root->left, sum, sum_t, temp, result);
                recur(root->right, sum, sum_t, temp, result);
                temp.pop_back();
            }
        }
    }
};