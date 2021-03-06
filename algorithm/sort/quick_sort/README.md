#快速排序#

*   步骤：
*   （1）选择pivot
*   （2）partition：重拍序列，所有比pivot小的都放在左边的部分，所有比pivot大的都放在右边部分。等于pivot的既可以放在左边，也可以放在右边。注意，数组可能被分为长度不同的两部分。
*   （3）Sort both parts. Apply quicksort algorithm recursively to the left and the right parts.

*   额外空间消耗：O(1)    
*   平均时间复杂度：O(n logn)
*   最差时间复杂的：O(n2)

##复杂度分析##
*   最差的情况下，时间复杂度为O(n)，但是，即使如此，在最实际的数据情况下，快排运行的很好，性能也超出其他的O(n logn)排序算法。

##其他##
*   函数partition除了可以用在快速排序中，还可以用来实现在长度为n的数组中查找第k大的数。
*   面试题“数组中出现次数超过一半的数字”和面试题“最小的k个数”都可以用这个函数来解决。

#三种快排方式，四种优化方法#
##三种快排方式————依据pivot的选取##
*   固定位置
*   随机选取基准
*   三数取中

##四种优化方法##
*   当待排序序列的长度分割到一定大小后，使用插入排序。
*   在一次分割结束后，可以把与Key相等的元素聚在一起，继续下次分割时，不用再对与key相等元素分割。
*   优化递归操作————尾递归（其实是模拟尾递归）
    -   尾调用：就是指某个函数的最后一步是调用另一个函数。
    -   "尾调用优化"（Tail call optimization），即只保留内层函数的调用记录。如果所有函数都是尾调用，那么完全可以做到每次执行时，调用记录只有一项，这将大大节省内存。这就是"尾调用优化"的意义。
    -   尾递归：函数调用自身，称为递归。如果尾调用自身，就称为尾递归。
    -   对于尾递归来说，由于只存在一个调用记录，所以永远不会发生"栈溢出"错误。
    -   因为原始的递归调用是个二叉树，而模拟尾递归的调用是个多叉树，在同样的递归次数下，模拟尾递归的深度小，不易发生栈的溢出操作。
*   使用并行或多线程处理子序列
