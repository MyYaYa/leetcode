#Solution#

*   首先要理解题目中path的含义。
*   使用深度优先搜索，针对每个dfs时的root，记录左右子树可以返回的最大值，结合当前节点的值，记录最大路径和。
*   当前dfs结果只会返回左右子树中值最大的那个加上当前节点的值。
