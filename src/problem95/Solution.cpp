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
    vector<TreeNode*> generateTrees(int n) {
        if (n < 1) {
            return vector<TreeNode*> ();
        }
        return gene(1, n);
    }

    vector<TreeNode*> gene(int start, int end) {
        if (start > end) {
            return vector<TreeNode*>(1, NULL);
        }

        if (start == end) {
            return vector<TreeNode*>(1, new TreeNode(start));
        }
        vector<TreeNode*> result;
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> lv = gene(start, i-1);
            vector<TreeNode*> rv = gene(i+1, end);

            for (auto l : lv) {
                for (auto r : rv) {
                    TreeNode* t = new TreeNode(i);
                    t->left = l;
                    t->right = r;
                    result.push_back(t);
                }
            }
        }
        return result;
    }
};