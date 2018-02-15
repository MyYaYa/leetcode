class Solution {
public:
    double Power(double base, int exponent) {
        if (exponent == 0)  return 1;
        // consider that base is zero.
        if (base == 0)  return 0;
        double result;
        if (exponent > 0) {
            result = PowerWithAbs(base, exponent);
        } else {
            result = 1 / PowerWithAbs(base, -exponent);
        }
        return result;
    }

    // bitwise operation is better than +-*/%
    double PowerWithAbs(double base, int exponent) {
        if (exponent == 0)  return 1;
        double result = PowerWithAbs(base, exponent >> 1);
        result *= result;
        if (exponent & 0x01)    result *= base;
        return result;
    }
};