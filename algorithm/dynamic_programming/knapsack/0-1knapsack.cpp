// recursively, not dynamic programming, exists redundance.
int knapsack(int W, vector<int>& vals, vector<int>& weights) {
    if (W <= 0 || vals.empty() || weights.empty() || vals.size() != weights.size())
        return 0;
    int len = vals.size();
    return knapsack(W, vals, weights, len);
}

int knapsack(int W, vector<int>& vals, vector<int>& weights, int n) {
    if (W <= 0 || n <= 0)
        return 0;
    if (weights[n-1] > W) {
        return knapsack(W, vals, weights, n-1);
    } else {
        return max(vals[n-1] + knapsack(W-weights[n-1], vals, weights, n-1),
            knapsack(W, vals, weights, n-1));
    }
}


// dynamic programming.
class Solution {
public:
    int knapsack(int W, vector<int>& vals, vector<int>& weights) {
        if (W <= 0 || vals.empty() || weights.empty() || vals.size() != weights.size())
            return 0;
        int len = vals.size();
        vector<vector<int>> dp(W + 1, vector<int>(len+1, 0));
        for (int w = 1; w <= W; w++) {
            for (int i = 1; i <= len; i++) {
                if (weights[i-1] > w) {
                    dp[w][i] = dp[w][i-1];
                } else {
                    dp[w][i] = max(vals[i-1]+dp[w-weights[i-1]][i-1], dp[w][i-1]);
                }
            }
        }
        return dp[W][len];
    }
};