class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head)  return NULL;
        if (!head->next)    return head;
        ListNode* front = new ListNode(-1);
        front->next = head;
        ListNode* fast = head->next;
        ListNode* slow = front;
        bool j = false;
        while(fast) {
            while (fast && fast->val == slow->next->val) {
                j = true;
                fast = fast->next;
            }
            if (j) {
                j = false;
                slow->next = fast;
                if (fast)
                    fast = fast->next;
            } else {
                if (fast) {
                    fast = fast->next;
                    slow = slow->next;
                }
            }
        }
        return front->next;
    }
};