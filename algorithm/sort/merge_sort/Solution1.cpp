class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (!head || !head->next)  return head;
        ListNode* middle = findMiddle(head);
        ListNode* right = sortList(middle->next);
        middle->next = NULL;
        ListNode* left = sortList(head);
        return mergeLists(left, right);
    }
    ListNode* findMiddle(ListNode* head) {
        ListNode* fast = head->next, * slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* mergeLists(ListNode* l1, ListNode* l2) {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        ListNode* front = new ListNode(0);
        ListNode* tmp = front;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tmp->next = l1;
                l1 = l1->next;
            } else {
                tmp->next = l2;
                l2 = l2->next;
            }
            tmp = tmp->next;
        }
        if (l1) {
            tmp->next = l1;
        }
        if (l2) {
            tmp->next = l2;
        }
        return front->next;
    }
};
