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
