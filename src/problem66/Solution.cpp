class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        int c = 0;
        int sum = digits[len-1] + 1;
        c = sum/10;
        digits[len-1] = sum%10;
        for (int i = len-2; i >= 0; i--) {
            sum = digits[i]+c;
            digits[i] = sum%10;
            c = sum/10;
        }
        if (c > 0) {
            digits.insert(digits.begin(), c);
        }
        return digits;
    }
};