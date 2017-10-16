class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0)   return INT_MAX;
        if (dividend == 0)  return 0;
        int flag = 1;
        if ((dividend<0 && divisor>0)||(dividend>0 && divisor<0))   flag = -1;
        long long dividend_tmp = abs((long long)dividend);
        long long divisor_tmp = abs((long long)divisor);
        if (dividend_tmp < divisor_tmp) return 0;
        long long result = 0;

        while (dividend_tmp >= divisor_tmp){
            long long tmp = divisor_tmp;
            int count = 0;
            while (tmp <= dividend_tmp) {
                tmp = tmp << 1;
                count ++;
            }
            result = result + ((long long)1 << (count - 1));
            dividend_tmp -= (tmp >> 1);
        }

        if (result > INT_MAX) {
            if (flag == 1)  return INT_MAX;
            else if (flag == -1)    return INT_MIN;
        }
        return result * flag;
    }
};