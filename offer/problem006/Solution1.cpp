class Solution {
public:
    int jumpFloor(int number) {
        if (number == 1)    return 1;
        if (number == 2)    return 2;
        int jump1 = 1;
        int jump2 = 2;
        int jump;
        for (int i = 3; i <= number; i++) {
            jump = jump1 + jump2;
            jump1 = jump2;
            jump2 = jump;
        }
        return jump;
    }
};