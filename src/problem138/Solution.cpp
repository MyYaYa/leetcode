class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head)  return NULL;
        RandomListNode* runner = head;
        RandomListNode* newHead = new RandomListNode(head->label);
        RandomListNode* newRunner = newHead;
        map<RandomListNode*, RandomListNode*> map;
        while (runner->next) {
            map[runner] = newRunner;
            runner = runner->next;
            newRunner->next = new RandomListNode(runner->label);
            newRunner = newRunner->next;
        }
        map[runner] = newRunner;
        runner = head;
        newRunner = newHead;
        while(runner->next) {
            newRunner->random = map[runner->random];
            runner = runner->next;
            newRunner = newRunner->next;
        }
        newRunner->random = map[runner->random];
        return newHead;
    }
};