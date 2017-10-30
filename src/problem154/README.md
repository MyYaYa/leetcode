#Solution#

*	对于旋转后的有序序列，其中存在重复的值，依然使用二分查找。
*	先判断left到right是否已经是有序序列，是的话，直接return nums[left]
*	然后判断left,mid,right中的有序区间，在非有序区间内寻找最小值。
*	存在nums[mid]==nums[left]的特殊情况，此时稍微变动下left，即left++。
*	最终循环退出，得到相邻的left和right，返回较小的那个值，就是最终结果。