#第一个只出现一次的字符#

*   利用空间换时间，使用长度为128的hash表。
*   第一次循环记录每个字符的出现次数。
*   第二次循环，找到第一个出现次数为1的字符，返回其index。