// convert to 0-1 knapsack
class Solution {
public:
    int knapsack(int W, vector<int>& vals, vector<int>& weights, vector<int>& nums) {
        if (W <= 0 || vals.empty() || weights.empty() || nums.empty() ||
                vals.size() != weights.size() || vals.size() != nums.size())
            return 0;
        int len = vals.size();
        vector<int> dp(W + 1, 0);
        for (int i = 0; i < len; i++) {
            for (int k = 0; k < nums[i]; k++) {
                for (int j = W; j >= weights[i]; j--) {
                    dp[j] = max(dp[j], dp[j-weights[i]] + vals[i]);
                }
            }
        }
        return dp[W];
    }
};

// mix 0-1 and complete knapsack
class Solution1 {
public:
    // simple 01 knapsack child problem
    void zeroOneKnapsack(int val, int weight, int capacity) {
        for (int i = capacity; i >= weight; i--) {
            dp[i] = max(dp[i], dp[i - weight] + val);
        }
    }

    // simple complete kanpsack child problem
    void completeKnapsack(int val, int weight, int capacity) {
        for (int i = weight; i <= capacity; i++) {
            dp[i] = max(dp[i], dp[i - weight] + val);
        }
    }

    int knapsack(int W, vector<int>& vals, vector<int>& weights, vector<int>& nums) {
        if (W <= 0 || vals.empty() || weights.empty() || nums.empty() ||
                vals.size() != weights.size() || vals.size() != nums.size())
            return 0;
        int len = vals.size();
        dp = vector<int>(W + 1, 0);
        for (int i = 0; i < len; i++) {
            if (nums[i] * weights[i] > W) {
                // equal to complete knapsack problem
                completeKnapsack(vals[i], weights[i], W);
            } else {
                // binary format, using 01 knapsack
                int k = 1;
                while (k < nums[i]) {
                    zeroOneKnapsack(k*vals[i], k*weights[i], W);
                    nums[i] -= k;
                    k << 1;
                }
                zeroOneKnapsack(nums[i]*vals[i], nums[i]*weights[i], W);
            }
        }
        return dp[W];
    }
private:
    vector<int> dp;
};