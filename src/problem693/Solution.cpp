class Solution {
public:
    bool hasAlternatingBits(int n) {
        int m = -1;
        while (n > 0) {
            if (n % 2 == m)
                return false;
            m = n % 2;
            n = n / 2;
        }
        return true;
    }
};