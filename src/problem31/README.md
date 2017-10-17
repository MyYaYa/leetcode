#Solution#

*	如果一个num squence已经是倒序排列，那么这个序列已经是最大的，类比到子序列，如果子序列已经是完全倒序排列，那么子序列已经最大
*	比如在a[i]比a[i-1]大的情况下，交换just greater than a[i-1]的a[j]（j >=i-1）与a[i-1]，右边的子序列依然最大（倒序）
*	完成交换后，在对右边的子序列进行reverse操作就能得到想要的结果
*	algorithm包含对vector的reverse操作方法
