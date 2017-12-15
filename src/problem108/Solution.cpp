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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty())   return NULL;
        return arrayToBST(nums, 0, nums.size()-1);
    }

    TreeNode* arrayToBST(vector<int>& nums, int start, int end) {
        if (end < start)   return NULL;
        int mid = (start + end) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = arrayToBST(nums, start, mid-1);
        node->right = arrayToBST(nums, mid+1, end);
        return node;
    }
};