// dynamic programming
class Solution {
public:
    int knapsack(int W, vector<int>& vals, vector<int>& weights) {
        if (W <= 0 || vals.empty() || weights.empty() || vals.size() != weights.size())
            return 0;
        int len = vals.size();
        vector<vector<int>> dp(len + 1, vector<int>(W + 1, 0));
        for (int i = 1; i <= len; i++) {
            for (int w = 1; w <= W; w++) {
                int count = w / weights[i-1];
                for (int k = 1; k <= count; k++) {
                    dp[i][w] = max(dp[i-1][w], k*vals[i-1] + dp[i-1][w-k*weights[i-1]]);
                }
            }
        }
        return dp[len][W];
    }
};

// dynamic programming with rolling array
class Solution1 {
public:
    int knapsack(int W, vector<int>& vals, vector<int>& weights) {
        if (W <= 0 || vals.empty() || weights.empty() || vals.size() != weights.size())
            return 0;
        int len = vals.size();
        vector<int> dp(W + 1, 0);
        for (int i = 1; i <= len; i++) {
            for (int w = weights[i-1]; w <= W; w++) {
                dp[w] = max(dp[w], dp[w - weights[i-1]]+vals[i-1]);
            }
        }
        return dp[W];
    }
};