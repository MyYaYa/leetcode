#Solution#

*   寻找峰值，此题存在一个先决条件，就是存在多个峰值的话，可随意返回任意峰值所在的index。
*   二分查找的方法，判断mid是否是峰值，不是则判断是上坡还是下坡，进行相应的low和high的重新赋值操作。