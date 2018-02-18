/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if (!pHead || !pHead->next) return pHead;
        ListNode* pre = NULL;
        ListNode* node = pHead;
        ListNode* tmp;
        while (node) {
            tmp = node->next;
            node->next = pre;
            pre = node;
            node = tmp;
        }
        return pre;
    }
};