#Solution#

*   主要的思想是贪心算法。
*   把当前跳的范围定义为[curBegin, curEnd]，curFarthest是在这个范围内能走到的最远距离，一旦当前点到达curEnd，就启动一次跳跃，然后curEnd=curFarthest。保持这种思路进行下去。