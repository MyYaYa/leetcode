class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* front1 = new ListNode(-1);
        ListNode* front2 = new ListNode(-1);
        ListNode* tmp1 = front1;
        ListNode* tmp2 = front2;
        while (head) {
            if (head->val < x) {
                tmp1->next = head;
                tmp1 = tmp1->next;
                head = head->next;
            } else {
                tmp2->next = head;
                tmp2 = tmp2->next;
                head = head->next;
            }
        }
        tmp1->next = front2->next;
        tmp2->next = NULL;
        return front1->next;
    }
};