class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if (!pHead1) return pHead2;
        if (!pHead2) return pHead1;
        ListNode* newHead;
        if (pHead1->val < pHead2->val) {
            newHead = pHead1;
            newHead->next = Merge(pHead1->next, pHead2);
        } else {
            newHead = pHead2;
            newHead->next = Merge(pHead1, pHead2->next);
        }
        return newHead;
    }
};