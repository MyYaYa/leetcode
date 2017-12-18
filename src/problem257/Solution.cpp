class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string temp = "";
        dfs(root, temp, result);
        return result;
    }

    void dfs(TreeNode* root, string temp, vector<string>& result) {
        if (root) {
            int size = temp.length();
            if (!root->left && !root->right) {
                temp.append(to_string(root->val));
                result.push_back(temp);
            }
            temp.append(to_string(root->val) + "->");
            if (root->left) dfs(root->left, temp, result);
            if (root->right)    dfs(root->right, temp, result);
            temp = temp.substr(0, size);
        }
    }
};