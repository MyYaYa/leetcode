class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if (!pRoot1) return false;
        if (!pRoot2) return true;

        if (pRoot1->val == pRoot2->val) {
            return (HasSubtreeCore(pRoot1->left, pRoot2->left)
                    && HasSubtreeCore(pRoot1->right, pRoot2->right))
                   || (HasSubtree(pRoot1->left, pRoot2)
                       || HasSubtree(pRoot1->right, pRoot2));
        } else {
            return HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
        }
    }

    bool HasSubtreeCore(TreeNode* pRoot1, TreeNode* pRoot2) {
        if (!pRoot2) return true;
        if (!pRoot1) return false;
        return pRoot1->val==pRoot2->val &&
               HasSubtreeCore(pRoot1->left, pRoot2->left) &&
               HasSubtreeCore(pRoot1->right, pRoot2->right);
    }
};