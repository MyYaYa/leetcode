#Solution#

*	查找target的范围，采用二分法。
*	通过二分法找到nums[mid]==target后，对mid前后两个方向查找非target的值，确定边界。
*	二分达到left<right-1的边界条件后，还没有判定成功的话，考虑一下特殊情况。
*	left=right-1 和 left=right
*	从left开始判断是否等于target，找到第一个等于target，同上进行判定，最终确定范围。