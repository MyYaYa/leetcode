class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head==NULL)
            return NULL;
        if (k==0)
            return head;
        ListNode* front = new ListNode(-1);
        front->next = head;
        ListNode* fast;
        ListNode* slow;
        fast = head;
        slow = head;
        int len = 0;
        while (k-- > 0) {
            fast = fast->next;
            len++;
            if (fast==NULL) {
                fast = head;
                k = k % len;
            }
        }
        if (fast == head) {
            return head;
        }

        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        front->next = slow->next;
        fast->next = head;
        slow->next = NULL;
        return front->next;
    }
};