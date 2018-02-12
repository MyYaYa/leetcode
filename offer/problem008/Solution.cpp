class Solution {
public:
    int  NumberOf1(int n) {
        int count = 0;
        unsigned int x = 1;
        while (x) {
            if (n & x)
                count++;
            x = x << 1;
        }
        return count;
    }
};