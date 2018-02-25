/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
        if (!pHead)
            return NULL;
        map<RandomListNode* ,RandomListNode*> m;
        RandomListNode* front = new RandomListNode(-1);
        RandomListNode* clonedHead = front;
        // deep copy next pointer
        RandomListNode* pHeadBackup = pHead;
        while (pHead) {
            clonedHead->next = new RandomListNode(pHead->label);
            m[pHead] = clonedHead->next;
            pHead = pHead->next;
            clonedHead = clonedHead->next;
        }
        // deep copy random pointer
        pHead = pHeadBackup;
        clonedHead = front->next;
        while (pHead) {
            clonedHead->random = m[pHead->random];
            pHead = pHead->next;
            clonedHead = clonedHead->next;
        }
        return front->next;
    }
};