class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head)  return NULL;
        RandomListNode* newHead;
        RandomListNode* runner, *newRunner;

        for (runner = head; runner != NULL; runner = runner->next->next) {
            newRunner = new RandomListNode(runner->label);
            newRunner->next = runner->next;
            runner->next = newRunner;
        }

        newHead = head->next;
        for (runner = head; runner != NULL; runner = runner->next->next) {
            if (runner->random)
                runner->next->random = runner->random->next;
        }

        for (runner = head; runner != NULL; runner = runner->next) {
            newRunner = runner->next;
            runner->next = newRunner->next;
            if (newRunner->next)
                newRunner->next = runner->next->next;
        }

        return newHead;
    }
};