#构建乘积数组#

*   定义C[i] = A[0]*A[1]*...*A[i-1]，D[i]=A[i+1]*...*A[n-2]*A[n-1]。
*   C[i]可以用自上而下的顺序计算出来，即C[i]=C[i-1]*A[i-1]
*   类似的，D[i]=D[i+1]*A[i+1]