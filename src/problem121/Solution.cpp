class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)
            return 0;
        int min_v = prices[0];
        int max_profit = 0;
        for (auto i : prices) {
            max_profit = max(i-min_v, max_profit);
            min_v = min(i, min_v);
        }
        return max_profit;
    }
};