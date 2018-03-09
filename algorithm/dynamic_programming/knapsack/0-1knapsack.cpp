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
        vector<vector<int>> dp(len + 1, vector<int>(W + 1, 0));
        for (int i = 1; i <= len; i++) {
            for (int w = 1; w <= W; w++) {
                if (weights[i-1] > w) {
                    dp[i][w] = dp[i-1][w];
                } else {
                    dp[i][w] = max(vals[i-1]+dp[i-1][w-weights[i-1]], dp[i-1][w]);
                }
            }
        }
        return dp[len][W];
    }
};

// dynamic programming with rolling array
// !!!!!!
// This is wrong solution, because dp[w] will update a lot times in the loop of (i);
class Solution {
public:
    int knapsack(int W, vector<int>& vals, vector<int>& weights) {
        if (W <= 0 || vals.empty() || weights.empty() || vals.size() != weights.size())
            return 0;
        int len = vals.size();
        // vector<vector<int>> dp(len+1, vector<int>(W+1, 0));
        vector<int> dp(W + 1, 0);
        for (int i = 1; i <= len; i++) {
            for (int w = 1; w <= W; w++) {
                if (weights[i-1] > w) {
                    // dp[i][w] = dp[i-1][w];
                    dp[w] = dp[w];
                } else {
                    // dp[i][w] = max(vals[i-1]+dp[i-1][w-weights[i-1]], dp[i-1][w]);
                    dp[w] = max(vals[i-1]+dp[w-weights[i-1]], dp[w]);
                }
            }
        }
        return dp[W];
    }
};

// dynamic programming with rolling array.
// correct solution
class Solution {
public:
    int knapsack(int W, vector<int>& vals, vector<int>& weights) {
        if (W <= 0 || vals.empty() || weights.empty() || vals.size() != weights.size())
            return 0;
        int len = vals.size();
        vector<int> dp(W + 1, 0);
        for (int i = 1; i <= len; i++) {
            for (int w = W; w >= weights[i-1]; w--) {
                dp[w] = max(vals[i-1]+dp[w-weights[i-1]], dp[w]);
            }
        }
        return dp[W];
    }
};