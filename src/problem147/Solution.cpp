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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next)   return head;
        ListNode* newHead = new ListNode(head->val);
        head = head->next;
        ListNode* front = new ListNode(-1), * temp;
        front->next = newHead;
        while (head) {
            temp = front;
            ListNode* slide = front->next;
            while (1) {
                if (!slide) {
                    temp->next = new ListNode(head->val);
                    break;
                }
                if (head->val > slide->val) {
                    temp = slide;
                    slide = slide->next;
                    continue;
                }
                else {
                    temp->next = new ListNode(head->val);
                    temp->next->next = slide;
                    break;
                }
            }
            head = head->next;
        }
        return front->next;
    }
};