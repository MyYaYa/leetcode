class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        if (n == 0) return 0;
        string str = to_string(n);
        return NumberOf1(str);
    }

    int NumberOf1(string str) {
        if (str.empty())
            return 0;
        int len = str.size();
        int first = str[0] - '0';
        if (len == 1 && first > 0)
            return 1;
        if (len == 1 && first == 0)
            return 0;

        int numFirstDigit = 0;
        if (first > 1)
            numFirstDigit += (int)pow(10, len-1);
        else if (first == 1) {
            stringstream stream(str.substr(1));
            int num;
            stream >> num;
            numFirstDigit += (num + 1);
        }
        int numOtherDigits = first * (len-1) * (int)pow(10, len - 2);

        return numFirstDigit + numOtherDigits + NumberOf1(str.substr(1));
    }
};