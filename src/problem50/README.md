#Solution#

*	首先考虑的就是log(n)的解法，这时存在一个问题需要注意，就是计算n/2的pow时，最好首先计算出来，不要使用pow(x,n/2)*pow(x,n/2)，不然计算量陡增。
*	还需要注意n为正负两种情况。