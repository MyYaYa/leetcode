class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if (!pHead)
            return NULL;
        ListNode* meet = NULL;
        ListNode* slow = pHead->next;
        ListNode* fast;
        if (!slow)
            return NULL;
        fast = slow->next;
        while (slow && fast) {
            if (slow == fast) {
                meet = slow;
                break;
            }
            slow = slow->next;
            fast = fast->next;
            if (fast)
                fast = fast->next;
        }
        if (!meet)  return NULL;
        int loopLen = 0;
        while (slow->next != meet) {
            loopLen++;
            slow = slow->next;
            fast = fast->next->next;
        }
        loopLen++;
        slow = pHead; fast = pHead;
        for (int i = 0; i < loopLen; i++) {
            fast = fast->next;
        }
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};