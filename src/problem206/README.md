#Solution#

*   有两种解法，either iteratively or recursively。
*   迭代循环的方法：定义一个pre节点，把当前head节点的next指向pre,同时pre等于当前head节点，head节点等于head节点原始next。依次迭代循环下去。
*   递归的方法：先递归到最末节点，返回此最末节点作为新的头节点，同时把head->next->next等于head，并把head->next置为NULL，物理意义上就是从链表的结尾开始，替换原先向后指的指针，变为向前指的指针。