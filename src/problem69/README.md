#Solution#

*	二分法，找寻符合平方等于指定值的mid，如果最终退出了二分循环，则一定是low为想要的答案。
*	注意int类型的平方会溢出的问题，所以需要使用long long类型防止溢出。