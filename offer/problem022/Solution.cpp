class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        return isSymmetrical(pRoot, pRoot);
    }
    
    bool isSymmetrical(TreeNode* pRoot1, TreeNode* pRoot2) {
        if (!pRoot1 && !pRoot2)
            return true;
        if (!pRoot1 || !pRoot2)
            return false;
        if (pRoot1->val != pRoot2->val)
            return false;
        return isSymmetrical(pRoot1->left, pRoot2->right) 
               && isSymmetrical(pRoot1->right, pRoot2->left);
    }
};