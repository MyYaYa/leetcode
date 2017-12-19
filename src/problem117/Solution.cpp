/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode* cur = root;
        TreeLinkNode* head = NULL;
        TreeLinkNode* run = NULL;
        while (cur) {
            while (cur) {
                if (cur->left) {
                    if (run) {
                        run->next = cur->left;
                    } else {
                        head = cur->left;
                    }
                    run = cur->left;
                }
                if (cur->right) {
                    if (run) {
                        run->next = cur->right;
                    } else {
                        head = cur->right;
                    }
                    run = cur->right;
                }
                cur = cur->next;
            }
            cur = head;
            head = NULL;
            run = NULL;
        }
    }
};