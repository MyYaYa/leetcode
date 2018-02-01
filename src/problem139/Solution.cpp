class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.size();
        vector<bool> dp(len+1, false);
        dp[0] = true;
        for (int i = 1; i <= len; i++) {
            for (int j = 0; j < len; j++) {
                string substr = s.substr(j, i-j);
                if (dp[j] && find(wordDict.begin(), wordDict.end(), substr) != wordDict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[len];
    }
};