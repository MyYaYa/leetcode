#礼物的最大价值#

*   递归，利用动态规划求解。
*   二维动态规划数组存在可优化的空间，因为当前位置的价值只与left和up有关，所以考虑只使用一位数组进行动态规划求解。
*   注意动态规划数组的长度确定，以及访问礼物矩阵的数组越界。