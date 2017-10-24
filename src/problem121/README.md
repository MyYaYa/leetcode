#Solution#

*	类似53题MaxSubArray，从头遍历，更新最小值，以及（当前值-最小值）与Max_Profit比较更新Max_Profit
*	另外一种解法，利用买入时储蓄，卖出时储蓄，这两个变量，循环数组进行最大利润的计算。