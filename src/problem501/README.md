#Solution#

*   利用map数据结构，在遍历的同时，保存节点重复的信息，时间复杂度O(n)，空间复杂度为O(n)。
*   题目又提出了如果只使用O(1)的空间复杂度该如何解决的问题。
*   此时，题目默认重复节点只存在于右子树且重复节点为连续出现，所以，通过特殊方法可以解决。
*   中序遍历两次二叉搜索树，第一次记录最大出现次数。
*   第二次寻找最大出现次数的那个节点值，并进行保存，返回结果。