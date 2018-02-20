/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        if (!pRoot)
            return vector<vector<int>>();
        vector<vector<int>> result;
        stack<TreeNode*> stk[2];
        int cur = 0;
        int next = 1;
        stk[cur].push(pRoot);
        while (!stk[0].empty() || !stk[1].empty()) {
            int len = stk[cur].size();
            TreeNode* tmp;
            vector<int> line;
            for (int i = 0; i < len; i++) {
                tmp = stk[cur].top();
                line.push_back(tmp->val);
                stk[cur].pop();
                if (cur == 0) {
                    if (tmp->left)  stk[next].push(tmp->left);
                    if (tmp->right) stk[next].push(tmp->right);
                } else {
                    if (tmp->right) stk[next].push(tmp->right);
                    if (tmp->left)  stk[next].push(tmp->left);
                }
            }
            result.push_back(line);
            cur = 1 - cur;
            next = 1 - next;
        }
        return result;
    }
};