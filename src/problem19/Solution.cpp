/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* front = new ListNode(0);
        ListNode* slow = new ListNode(0);
        front->next = head;
        slow = front;
        ListNode* fast = front;
        for(int i = 0; i < n; i++) {
            fast = fast->next;
        }
        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* t = slow->next->next;
        delete(slow->next);
        slow->next = t;
        return front->next;
    }
};