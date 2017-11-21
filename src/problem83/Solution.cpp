class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode* front = new ListNode(-1);
        front->next = head;
        ListNode* cur = head;
        while (cur->next != NULL) {
            if (cur->val == cur->next->val) {
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }
        return front->next;
    }
};