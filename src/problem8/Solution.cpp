class Solution {
public:
    int myAtoi(string str) {
        if (str.empty())    return 0;
        int index = 0;
        while (str[index] == ' ')   ++index;
        long long result = 0;
        int sign = 1;
        if (str[index] == '-') {
            ++index;
            sign = -1;
        } else if (str[index] == '+') {
            ++index;
            sign = 1;
        }
        for (int i = index; i < str.size(); ++i) {
            if (str[i] >= '0' && str[i] <= '9') {
                result = result * 10 + (int)(str[i]-'0');
                if (result > INT_MAX) {
                    return sign==1 ? INT_MAX : INT_MIN;
                }
            } else {
                break;
            }
        }
        return sign == 1 ? result : -result;
    }
};