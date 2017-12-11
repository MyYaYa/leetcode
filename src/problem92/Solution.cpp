class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m==n)   return head;
        ListNode front(-1);
        front.next = head;
        ListNode* prehead = &front;
        int times = n-m;
        while(--m)  prehead = prehead->next;
        ListNode* cur = prehead->next;
        ListNode* tail = cur;
        ListNode* pre = NULL;
        for (int i = 0; i <= times; i++) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        prehead->next = pre;
        tail->next = cur;

        return front.next;
    }
};