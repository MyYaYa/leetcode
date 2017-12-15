class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root)  return result;
        queue<TreeNode*> q;
        q.push(root);
        bool lefttoright = true;
        while (!q.empty()) {
            int size = q.size();
            vector<int> tmp(size);
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                int index = lefttoright ? i : size - 1 - i;
                tmp[index] = node->val;
                if (node->left) q.push(node->left);
                if (node->right)    q.push(node->right);
            }
            result.push_back(tmp);
            lefttoright = !lefttoright;
        }
        return result;
    }
};