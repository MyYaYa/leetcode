#插入排序#

*   插入排序的过程中，数组被想象成分为了两部分————有序和无序的。
*   插入排序的主要操作就是插入，任务就是在有序的部分插入值。这种插入操作是有很多变种的。

*   （1）"Sifting down" using swap：交换着相邻的元素，直到应当插入的位置，就像冒泡排序一样。
*   （2）Shifting instead of swapping：先把较大的向后移动，然后在正确的位置一插即中，避免了没有必要的swap操作
*   （3）Using binary search：二分查找找到合适的插入位置，然后移动有序序列中应当向后移动的部分，然后插入值。所以即使使用了二分查找的方法，时间复杂度依然O(n2)。但二分查找减少了比较的次数，还是有优化的。

*   额外空间消耗：O(1)
*   平均时间复杂度：O(n2)
*   最差时间复杂度：O(n2)

##插入排序的特性##
*   adaptive (performance adapts to the initial order of elements);
*   stable (insertion sort retains relative order of the same elements);
*   in-place (requires constant amount of additional space);
*   online (new elements can be added during the sort).


*   对链表进行插入排序，思路一致，注意链表的指针操作以及链表存储的特殊性。
