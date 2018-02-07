class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        if (!head) return vector<int>();
        stack<ListNode*> stk;
        while (head) {
            stk.push(head);
            head = head->next;
        }
        vector<int> result;
        while (!stk.empty()) {
            ListNode* tmp = stk.top();
            stk.pop();
            result.push_back(tmp->val);
        }
        return result;
    }
};