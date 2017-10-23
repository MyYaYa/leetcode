class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len < 2)
            return 0;
        int last = prices[0];
        int min_v = prices[0];
        int max_profit = 0;
        int profit = 0;
        for (int i = 1; i < len; i++) {
            if (prices[i] <= last) {
                max_profit += profit;
                profit = 0;
                min_v = prices[i];
            }
            if (prices[i] > min_v) {
                profit = max(prices[i] - min_v, profit);
            }
            last = prices[i];
        }
        max_profit += profit;
        return max_profit;
    }
};