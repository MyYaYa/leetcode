class Solution {
public:
    int jumpFloorII(int number) {
        int fib = 1;
        for (int i = 1; i < number; i++) {
            fib *= 2;
        }
        return fib;
    }
};