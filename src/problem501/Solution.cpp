class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> result;
        int max_counts, value, counts;
        inorder(root, max_counts=0, value=INT_MIN, counts=0);
        cout << max_counts;
        inorder(root, result, max_counts, value=INT_MIN, counts=0);
        return result;
    }

    void inorder(TreeNode* root, int& max_counts, int& value, int& counts) {
        if (!root)
            return;
        inorder(root->left, max_counts, value, counts);
        if (root->val==value) {
            counts++;
        } else {
            value = root->val;
            counts = 1;
        }
        max_counts = max(max_counts, counts);
        inorder(root->right, max_counts, value, counts);
    }

    void inorder(TreeNode* root, vector<int>& result, int& max_counts, int& value, int& counts) {
        if (!root)
            return;
        inorder(root->left, result, max_counts, value, counts);
        if (root->val == value) {
            counts++;
        } else {
            value = root->val;
            counts = 1;
        }
        if (max_counts == counts)   result.push_back(root->val);
        inorder(root->right, result, max_counts, value, counts);
    }
};