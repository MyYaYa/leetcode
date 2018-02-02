class Solution {
public:
    void reorderList(ListNode* head) {
        // three situations which needs to return directly
        if (!head || !head->next || !head->next->next) return;
        // find the middle node, split into two lists
        ListNode* slow = head, * fast = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* newHead = slow->next;
        slow->next = NULL;


        // reverse the second half list: O(n)
        ListNode* node = newHead->next;
        newHead->next = NULL;
        while (node) {
            auto t = node->next;
            node->next = newHead;
            newHead = node;
            node = t;
        }

        // merge two list: O(n)
        for (fast = head, slow = newHead; fast && slow;) {
            auto t = fast->next;
            fast->next = slow;
            auto t1 = slow->next;
            slow->next = t;
            fast = t;
            slow = t1;
        }
    }
};