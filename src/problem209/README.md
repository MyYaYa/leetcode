#Solution#

*   在数组中寻找最短的子序列，此子序列之和大于等于target。
*   从头开始寻找，累加sum，当sum大于target时，移动子序列的头指针，接着寻找，同时记录最短长度。
*   题目还要求时间复杂度为O(nlog(n))的解法，此时先计算累加数组sums[]，对于每一个在sums[]中大于target的值sums[i]，都向前寻找，利用binary search寻找第一个大于(sums[i]-target)的值sum[j]，此时，j跟i对应的原数组中的值就是加和刚大于target的子序列，循环比较长度，得到结果。