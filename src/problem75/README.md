#Solution#

*   最简单的方法就使counting sort，记录0，1，2的个数，总之是经过2-pass来完成最终的结果输出。
*   one-pass in place的解法是，遍历数组，直接在数组内进行替换操作。
*   定义begin，end， 每经过一个元素，如果是0，则与begin替换，begin++。如果是2，则与end替换，end--。
*   最终遍历到end位置就结束，继续遍历的话会出现错误。因为end已经跑到1的区域了。