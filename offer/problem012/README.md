#删除链表中重复的结点#

*   为了保证删除之后的链表仍然是相连的，我们要把当前节点的前一个节点(pPreNode)和后面值比当前节点值大的节点相连。我们要确保pPreNode始终与下一个没有重复的节点连接在一起