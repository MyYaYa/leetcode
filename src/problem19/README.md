#Solution#

*	leetcode的linkedlist都是没有头节点的，所以自己声明一个头节点。
*	只需一次linkedlist的循环，	定义fast和slow两个指针，fast首先next到n的位置，然后fast和slow同时next。
*	然后把slow的next替换为slow的next->next，同时记得删除没用的指针。