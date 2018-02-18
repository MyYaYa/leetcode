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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if (!pListHead || k == 0)
            return NULL;
        ListNode* ahead = pListHead;
        ListNode* behind = pListHead;
        for (int i = 0; i < k; i++) {
            if (!ahead) return NULL;
            ahead = ahead->next;
        }
        
        while (ahead) {
            ahead = ahead->next;
            behind = behind->next;
        }
        
        return behind;
    }
};