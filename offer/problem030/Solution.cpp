class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if (!pRootOfTree)   return NULL;
        TreeNode* pLastNode = NULL;
        pLastNode = SubConvert(pRootOfTree, pLastNode);
        while (pLastNode && pLastNode->left) {
            pLastNode = pLastNode->left;
        }
        return pLastNode;
    }

    TreeNode* SubConvert(TreeNode* pRoot, TreeNode* pLastNode) {
        if (!pRoot) return NULL;
        TreeNode* pCurrent = pRoot;
        if (pRoot->left)
            pLastNode = SubConvert(pRoot->left, pLastNode);
        pCurrent->left = pLastNode;
        if (pLastNode) {
            pLastNode->right = pCurrent;
        }
        pLastNode = pCurrent;
        if (pCurrent->right)
            pLastNode = SubConvert(pCurrent->right, pLastNode);
        return pLastNode;
    }
};