class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if (data.size() < 2)    return;
        int xor_result = 0;
        for (auto i : data) {
            xor_result ^= i;
        }

        int index = 0;
        while (((xor_result & 1) == 0) && index < 32) {
            xor_result = xor_result >> 1;
            ++index;
        }

        *num1 = 0;
        *num2 = 0;
        for (auto i : data) {
            int tmp = i >> index;
            if ((tmp & 1) == 0) {
                *num1 ^= i;
            } else {
                *num2 ^= i;
            }
        }
    }
};