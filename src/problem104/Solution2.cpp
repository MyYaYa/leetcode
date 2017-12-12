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
        queue<TreeNode*> queue;
        if (root)
            queue.push(root);
        int result = 0;
        while (!queue.empty()) {
            ++result;
            int len = queue.size();
            for (int i = 0; i < len; i++) {
                TreeNode *tmp = queue.front();
                queue.pop();
                if (tmp->left)
                    queue.push(tmp->left);
                if (tmp->right)
                    queue.push(tmp->right);
            }
        }
        return result;
    }
};