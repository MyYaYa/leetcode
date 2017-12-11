class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) return 0;
        int len = s.size();
        if (len == 1 && isValid(s[0]))
            return 1;
        int dp[len+1];
        dp[0] = 1;
        if (isValid(s[0]))
            dp[1] = 1;
        else
            dp[1] = 0;
        for (int i = 1; i < len; i++) {
            dp[i+1] = 0;
            if (isValid(s[i]))
                dp[i+1] += dp[i];
            if (isValid(s[i-1], s[i]))
                dp[i+1] += dp[i-1];
        }
        return dp[len];
    }

    bool isValid(char a, char b) {
        return a == '1' || (a == '2' && b <= '6' && b >= '0');
    }
    bool isValid(char a) {
        return a > '0' && a <= '9';
    }
};