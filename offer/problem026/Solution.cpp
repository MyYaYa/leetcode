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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        if (!root)
            return vector<int>();
        vector<int> result;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* tmp;
            int len = q.size();
            for (int i = 0; i < len; i++) {
                tmp = q.front();
                q.pop();
                result.push_back(tmp->val);
                if (tmp->left) q.push(tmp->left);
                if (tmp->right)  q.push(tmp->right);
            }
        }
        return result;
    }
};

// another while method
class Solution1 {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        if (!root)
            return vector<int>();
        vector<int> result;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* tmp;
            tmp = q.front();
            q.pop();
            result.push_back(tmp->val);
            if (tmp->left) q.push(tmp->left);
            if (tmp->right)  q.push(tmp->right);
        }
        return result;
    }
};