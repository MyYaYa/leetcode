class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* front = new ListNode(-1);
        front->next = head;
        ListNode* prehead = front;
        for (int i = 0; i < m-1; i++)
            prehead = prehead->next;
        ListNode* cur = prehead->next;
        for (int i = 0; i < n-m; i++) {
            ListNode* node = cur->next;
            cur->next = node->next;
            node->next = prehead->next;
            prehead->next = node;
        }
        return front->next;
    }
};