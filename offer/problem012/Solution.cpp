/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if (!pHead || !pHead->next) return pHead;
        ListNode* front = new ListNode(-1);
        front->next = pHead;
        ListNode* pre = front;
        ListNode* pNode = pHead;
        while (pNode) {
            ListNode* pNext = pNode->next;
            if (pNext && pNext->val == pNode->val) {
                int value = pNode->val;
                ListNode* del = pNode;
                delete del;
                while (pNext && pNext->val == value) {
                    del = pNext;
                    pNext = pNext->next;
                    delete del;
                }
                pre->next = pNext;
                pNode = pNext;
            } else {
                pre = pNode;
                pNode = pNext;
            }
        }
        return front->next;
    }
};