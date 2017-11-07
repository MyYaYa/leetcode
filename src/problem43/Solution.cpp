class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        if (len1 == 0 || len2 == 0) {
            return "0";
        }
        string sum(len1+len2, '0');
        for (unsigned int i = 0; i < len1; i++) {
            int carry = 0;
            for (unsigned int j = 0; j < len2; j++) {
                int s = (num1[len1-i-1]-'0') * (num2[len2-j-1] - '0') + (sum[len1+len2-1-i-j]-'0') + carry;
                carry = s/10;
                sum[len1+len2-1-i-j] = s % 10 + '0';
            }
            sum[len1-1-i] += carry;
        }
        size_t pos = sum.find_first_not_of('0');
        if (pos == string::npos)
            return "0";
        return sum.substr(pos);
    }
};