#两个链表的第一个公共节点#

*   排除暴力解，可以使用两个辅助栈，分别把两个链表压入栈，从栈顶确定第一个公共节点。
*   还有一种不需要辅助空间的方法，就是遍历两个链表，得到两个链表的长度，然后对齐后进行比较，找到第一个公共节点，或者遍历到结尾NULL指针，返回NULL。