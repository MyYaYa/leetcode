class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)   return head;
        ListNode* slow = head, * fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* h2 = sortList(slow->next);
        slow->next = NULL;
        return merge(sortList(head), h2);
    }

    ListNode* merge(ListNode* h1, ListNode* h2) {
        if (!h1)    return h2;
        if (!h2)    return h1;
        ListNode* front = new ListNode(-1);
        ListNode* head = front;
        while (h1 && h2) {
            if (h1->val > h2->val) {
                head->next = new ListNode(h2->val);
                head = head->next;
                h2 = h2->next;
            } else {
                head->next = new ListNode(h1->val);
                head = head->next;
                h1 = h1->next;
            }
        }
        while (h1) {
            head->next = new ListNode(h1->val);
            head = head->next;
            h1 = h1->next;
        }
        while (h2) {
            head->next = new ListNode(h2->val);
            head = head->next;
            h2 = h2->next;
        }
        return front->next;
    }
};