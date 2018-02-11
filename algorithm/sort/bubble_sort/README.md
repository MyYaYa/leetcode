#冒泡排序#

*   冒泡排序，以升序排序为例。
*   从头开始遍历数组，碰到前一个比后一个大，则交换邻近的两个，接着遍历下一个邻接对。
*   每一次遍历，就会把较大的那个像冒泡似的排序到最后，保证了升序的排列。

*   冒泡排序存在可以优化的空间，当没有逆序存在时，就可以结束排序了，在遍历过程中可以判断出逆序存在或者不存在（即当交换过程不在发生时，就说明数组已经有序了）。

*   额外空间消耗：O(1)
*   平均时间复杂度：O(n2)
*   最差时间复杂度：O(n2)

*   Bubble sort is stable and adaptive.
*   Adaptive means that for almost sorted array it gives O(n) estimation.
*   Turtles and Rabbits: Big elements(rabbits) go up fast, while small ones(turtles) go down very slow. 
*   鸡尾酒排序（Cocktail Sort）可以解决此问题，通过来回往返冒泡而不仅仅是单向冒泡。