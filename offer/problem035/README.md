#数据流的中位数#

*   左侧为最大堆，右侧为最小堆。
*   首先，要平均分配最小堆和最大堆的大小，当数据数为偶数时，插入最小堆，否则插入最大堆
*   还要保证，最大堆的元素全部小于最小堆中的元素。
*   所以当插入最大堆的时候，元素大于最小堆的一些元素的时候，应该先插入最小堆中，在返回最小堆的最小值，插入到最大堆中。
*   同理，当插入最小堆时发生类似情况时。

*   需要注意，与或运算的优先级低于 等于等于 运算符。