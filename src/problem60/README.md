#Solution#

*   又是数字序列的排列问题。
*   从结尾开始往前找倒叙子序列，然后在此子序列中寻找刚刚打过此子序列前一个数字的index，该index与此子序列前的那个数字交换位置，并对子序列重新排序，按照递增的顺序。