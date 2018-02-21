/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if (!root)
            return vector<vector<int>>();
        vector<vector<int>> result;
        vector<int> tmp;
        int now = 0;
        dfs(root, expectNumber, result, tmp, now);
        return result;
    }

    void dfs(TreeNode* root, int expectNumber, vector<vector<int>>& result, vector<int>& tmp, int now) {
        if (!root) {
            return;
        }
        if (!root->left && !root->right) {
            now += root->val;
            tmp.push_back(root->val);
            if (now == expectNumber) {
                result.push_back(tmp);
                tmp.pop_back();
                return;
            } else {
                tmp.pop_back();
                return;
            }
        } else {
            now += root->val;
            tmp.push_back(root->val);
            dfs(root->left, expectNumber, result, tmp, now);
            dfs(root->right, expectNumber, result, tmp, now);
            tmp.pop_back();
            return;
        }
    }
};