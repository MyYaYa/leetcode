#Solution#

*   依然使用层序遍历，最后把结果reverse就可以了。
*   我在层序遍历的时候使用了stack进行保存结果，然后再出栈得到结果。
*   看到了一种简洁的写法，感觉很是牛逼。
*   vector<vector<int> > (res.rbegin(), res.rend());
*   vector的构造函数可以使用两个Iterator进行初始化，这两个Iterator中间的内容就是初始化的结果。