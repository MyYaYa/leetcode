class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if (!root)  return result;
        queue<TreeNode*> q;
        stack<vector<int>> stk;
        q.push(root);
        while (!q.empty()) {
            int size  = q.size();
            vector<int> tmp;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                tmp.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right)    q.push(node->right);
            }
            stk.push(tmp);
        }
        while(!stk.empty()) {
            vector<int> v;
            v = stk.top();
            result.push_back(v);
            stk.pop();
        }
        return result;
    }
};