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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        ListNode* l3 = new ListNode(0);
        ListNode* r = l3;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                ListNode* p = new ListNode(l1->val);
                r->next = p;
                r = p;
                l1 = l1->next;
            }
            else {
                ListNode* p = new ListNode(l2->val);
                r->next = p;
                r = p;
                l2 = l2->next;
            }
        }
        while (l1) {
            ListNode* p = new ListNode(l1->val);
            r->next = p;
            r = p;
            l1 = l1->next;
        }
        while (l2) {
            ListNode* p = new ListNode(l2->val);
            r->next = p;
            r = p;
            l2 = l2->next;
        }
        ListNode* head;
        head = l3;
        l3 = l3->next;
        delete head;
        return l3;
    }
};