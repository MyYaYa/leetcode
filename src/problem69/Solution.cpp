class Solution {
public:
    int mySqrt(int x) {
        if (x==0)
            return 0;
        if (x==1)
            return 1;
        long long low = 1;
        long long high = x;
        while(low < high-1) {
            long long mid = (low + high) / 2;
            if (mid*mid == x)
                return mid;
            else if (mid*mid < x)
                low = mid;
            else
                high = mid;
        }
        return low;
    }
};