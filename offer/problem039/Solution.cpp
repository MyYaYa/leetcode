class Solution {
public:
    int GetTranslationCount(int number) {
        if (number < 0)
            return 0;
        string number_str = to_string(number);
        return GetTranslationCount(number_str);
    }

    int GetTranslationCount(string number_str) {
        vector<int> dp(number_str.size(), 0);
        dp[number_str.size() - 1] = 1;
        for (int i = number_str.size() - 2; i >= 0; --i) {
            dp[i] = dp[i+1];
            int digit1 = number_str[i] - '0';
            int digit2 = number_str[i+1] - '0';
            int converted = digit1*10 + digit2;
            if (converted >= 10 && converted < 26) {
                if (i == number_str.size() - 2)
                    dp[i] += 1;
                else
                    dp[i] += dp[i+2];
            }
        }
        return dp[0];
    }
};