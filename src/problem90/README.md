#Solution#

*   subset II，是problem78的衍生题。
*   此时允许数组中存在重复数字，在回退过程中需要判断特殊情况
*   if (i == begin || nums[i] != nums[i-1])，才进行回退操作，避免记录重复的结果。