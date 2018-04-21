class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if (dict.find(s) != dict.end())
            return true;
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                string s_str = s.substr(j, i - j);
                if (dict.find(s_str) != dict.end() && dp[j]) {
                    dp[i] = true;
                }
            }
        }
        return dp[s.size()];
    }
};
