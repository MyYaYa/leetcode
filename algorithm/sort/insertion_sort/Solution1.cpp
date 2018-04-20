class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if (!head || !head->next)
            return head;
        ListNode* front = new ListNode(0);
        ListNode* cur = head;

        while (cur) {
            ListNode* pNext = cur->next;
            ListNode* pNode = front;
            while (pNode->next != NULL && pNode->next->val < cur->val) {
                pNode = pNode->next;
            }
            cur->next = pNode->next;
            pNode->next = cur;
            cur = pNext;
        }

        return front->next;
    }
};
