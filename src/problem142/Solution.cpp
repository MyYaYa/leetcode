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
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                ListNode* pos = fast;
                ListNode* start = head;
                while (pos != start) {
                    pos = pos->next;
                    start = start->next;
                }
                return pos;
            }
        }
        return NULL;
    }
};