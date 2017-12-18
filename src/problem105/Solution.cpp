class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty())    return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        auto in_index = find(inorder.begin(), inorder.end(), preorder[0]);
        int left = in_index - inorder.begin();
        int right = inorder.end() - in_index;
        vector<int> pre_left = vector<int>(preorder.begin()+1, preorder.begin()+left+1);
        vector<int> pre_right = vector<int>(preorder.begin()+left+1, preorder.end());
        vector<int> in_left = vector<int>(inorder.begin(), inorder.begin()+left);
        vector<int> in_right = vector<int>(inorder.begin()+left+1, inorder.end());
        root->left = buildTree(pre_left, in_left);
        root->right = buildTree(pre_right, in_right);
        return root;
    }
};
