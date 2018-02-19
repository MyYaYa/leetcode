class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if (!pHead1) return pHead2;
        if (!pHead2) return pHead1;
        ListNode* front = new ListNode(-1);
        ListNode* node = front;
        while (pHead1 && pHead2) {
            if (pHead1->val < pHead2->val) {
                node->next = pHead1;
                node = pHead1;
                pHead1 = pHead1->next;
            } else {
                node->next = pHead2;
                node = pHead2;
                pHead2 = pHead2->next;
            }
        }
        if (pHead1) {
            node->next = pHead1;
        }
        if (pHead2) {
            node->next = pHead2;
        }
        return front->next;
    }
};