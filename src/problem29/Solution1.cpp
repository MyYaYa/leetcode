class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend==0x80000000 && divisor==-1) return 0x7fffffff;
        bool sign = (dividend>0) ^ (divisor>0);
        unsigned int dvd = abs(dividend), dvs = abs(divisor);
        if (dvd<dvs) return 0;
        int ans = 0;
        while (dvd>=dvs){
            unsigned int accum = dvs, temp = 1;
            while ((accum<=1<<30) && (dvd >= accum<<1)) accum <<= 1, temp <<=1;
            ans += temp, dvd -= accum;
        }
        return sign ? -ans : ans;
    }
};