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
    int sumNumbers(TreeNode* root) {
        if (!root)  return 0;
        vector<string> result;
        string temp = to_string(root->val);
        dfs(root, temp, result);
        int sum = 0;
        for (string i : result) {
            int v = stoi(i);
            sum += v;
        }
        return sum;
    }

    void dfs(TreeNode* root, string temp, vector<string>& result) {
        if (root->left) {
            temp.push_back(48 + root->left->val);
            dfs(root->left, temp, result);
            temp.pop_back();
        }
        if (root->right){
            temp.push_back(48 + root->right->val);
            dfs(root->right, temp, result);
            temp.pop_back();
        }
        if (!root->left && !root->right) {
            result.push_back(temp);
        }
    }
};