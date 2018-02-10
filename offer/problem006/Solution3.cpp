class Solution {
public:
    int rectCover(int number) {
        int r[2] = {1,2};
        if (number <= 2) return r[number-1];
        int result1 = 1;
        int result2 = 2;
        int result;
        for (int i = 3; i <= number; i++) {
            result = result1 + result2;
            result1 = result2;
            result2 = result;
        }
        return result;
    }
};