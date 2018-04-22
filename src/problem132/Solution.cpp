class Solution {
public:
    int minCut(string s) {
        if (s == "")
            return 0;
        vector<int> dp(s.size() + 1, 0);
        dp[s.size()] = -1;
        vector<vector<bool>> bm(s.size(), vector<bool>(s.size(), false));
        for (int i = s.size() - 1; i >= 0; --i) {
            dp[i] = INT_MAX;
            for (int j = i; j < s.size(); ++j) {
                if (s[j] == s[i] && (j - i < 2 || bm[i+1][j-1])) {
                    bm[i][j] = true;
                    dp[i] = min(dp[i], dp[j+1]+1);
                }
            }
        }
        return dp[0];
    }
};
