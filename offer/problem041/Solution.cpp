class Solution {
public:
    int LongestSubstringWithoutDuplication(const string& str) {
        int len = str.size();
        vector<int> dp(len+1, 0);
        dp[0] = 0;
        map<char, int> m;
        for (int i = 0; i < len; ++i) {
            if (m.find(str[i]) == m.end()) {
                dp[i+1] = dp[i] + 1;
                m[str[i]] = i;
            } else {
                if (i - m[str[i]] > dp[i])
                    dp[i+1] = dp[i] + 1;
                else {
                    dp[i+1] = i - m[str[i]];
                }
            }
        }
        return dp[len];
    }
};