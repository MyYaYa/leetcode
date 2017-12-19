#Solution#

*   需要注意，此时是一个完美的二叉树，即满二叉树。
*   需要两个节点，一个指向每一层的开始，一个在此层进行操作。
*   cur->left->next = cur->right
*   cur->right->next = cur->next->left