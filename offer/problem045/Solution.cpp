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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if (!pHead1 || !pHead2) return NULL;
        int len1 = 0, len2 = 0;
        ListNode* tmp1 = pHead1, * tmp2 = pHead2;
        while (tmp1) {
            ++len1;
            tmp1 = tmp1->next;
        }
        while (tmp2) {
            ++len2;
            tmp2 = tmp2->next;
        }
        tmp1 = pHead1;
        tmp2 = pHead2;
        if (len1 >= len2) {
            while (len1 > len2) {
                tmp1 = tmp1->next;
                --len1;
            }
        } else {
            while (len2 > len1) {
                tmp2 = tmp2->next;
                --len2;
            }
        }
        while (tmp1 != tmp2) {
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
        return tmp1;
    }
};