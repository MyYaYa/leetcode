#Solution#

*   链表操作，注意空指针。要删除所有重复的节点。
*   定义了快慢指针，方便当前操作。
*   如果遇见重复节点，fast指针就往前走，然后删掉从slow到fast之间的节点。然后slow->next=fast，fast=fast->next。
*   如果没有重复节点，slow和fast分别前进。