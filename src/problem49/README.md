#Solution#

*	使用stl中的multimap数据结构，可以存储同样key的键值对。
*	注意multimap中含有compare，可以对key进行自动排序。
*	使用equal_range来确定指定键的范围，进而获取最终结果。
*	还有lower_bound()和upper_bound()方法来确定指定键的范围。