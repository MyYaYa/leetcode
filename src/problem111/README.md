#Solution#

*   寻找二叉树中的最低深度。
*   递归的方法，不多赘述。
*   但是需要注意的是，如果其中一个子节点为NULL，而另一个不为空，则最低深度为1+minDepth(不为空的子节点)。
*   即只有两个子节点都为空才能算叶节点，否则不能当作一条从根节点到子节点的遍历路径。