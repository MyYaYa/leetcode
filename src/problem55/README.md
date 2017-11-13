#Solution#

*	考虑从起点开始，一步一步确定最远的距离。
*	记录max_reach为当前所能到达的最远距离。
*	比较i+nums[i]　与　max_reach得到这个最远距离。
*	如果i超过了reach的范围，则可以判定，不能到达末尾。