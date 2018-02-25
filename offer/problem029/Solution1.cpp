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
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if (!pHead)  return pHead;
        CloneNext(pHead);
        CloneRandom(pHead);
        return Cut(pHead);
    }

    void CloneNext(RandomListNode* head) {
        while (head) {
            RandomListNode* clone = new RandomListNode(head->label);
            RandomListNode* tmp = head->next;
            head->next = clone;
            clone->next = tmp;
            head = tmp;
        }
    }

    void CloneRandom(RandomListNode* head) {
        while (head) {
            RandomListNode* rand = head->random;
            if (rand)
                head->next->random = rand->next;
            head = head->next->next;
        }
    }

    RandomListNode* Cut(RandomListNode* head) {
        if (!head)  return head;
        RandomListNode* front = new RandomListNode(-1);
        front->next = head->next;
        while (head) {
            RandomListNode* clone = head->next;
            RandomListNode* tmp = head->next->next;
            head->next = tmp;
            head = tmp;
            if (tmp)
                clone->next = tmp->next;
        }
        return front->next;
    }
};