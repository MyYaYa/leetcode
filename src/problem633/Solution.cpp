class Solution {
public:
    bool judgeSquareSum(int c) {
        long long low = 0;
        long long high = sqrt(c);
        while (low <= high) {
            if (low*low+high*high > c)
                high--;
            else if (low*low+high*high==c)
                return true;
            else
                low++;
        }
        return false;
    }
};