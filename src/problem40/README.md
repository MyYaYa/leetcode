#Solution#

*	类似problem39，深度优先搜索 Depth First Search（DFS）。先给vector排好序。
*	但是需要注意，set中的元素只能使用一次，所以在递归过程中，begin=i+1而不是begin=i了。
*	还需要注意，因为有相同的元素，所以会得到重复的结果，需要注意排除这种特殊情况。
*	在for循环中，先判定是否前一元素等于当前元素，如果等于则跳过此次迭代，但如果当前元素为begin则不能忽略，否则会丢失掉值相同的元素同时被选中的情况，就得不到正确结果了。
*	重点就是————如何正确找到边界条件！！！