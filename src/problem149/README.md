#Solution#

*	使用hash存储斜率出现的个数，注意斜率不存在和点重复的问题。
*	考虑到double比较可能出现稍微误差，所以可以通过保留精度后转换成string来解决。