class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num==0 || num==1)
            return true;
        long long low = 1;
        long long high = num;
        while (low < high-1) {
            long long mid = (low + high) / 2;
            if (mid*mid == num)
                return true;
            else if (mid*mid < num)
                low = mid;
            else
                high = mid;
        }
        return false;
    }
};