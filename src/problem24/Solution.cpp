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
    ListNode* swapPairs(ListNode* head) {
        ListNode* parent = new ListNode(0);
        parent->next = head;
        head = parent;
        while(head) {
            ListNode *ch1, *ch2;
            if (head->next != NULL) {
                ch1 = head->next;
                if (ch1->next != NULL)
                    ch2 = ch1->next;
                else
                    break;
            } else
                break;
            ch1->next = ch2->next;
            ch2->next = ch1;
            head->next = ch2;
            head = ch1;
        }
        return parent->next;
    }
};