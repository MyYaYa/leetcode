class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MIN;
        int sell = 0;
        for (auto i : prices) {
            buy = max(buy, -i);
            sell = max(sell, buy+i);
        }
        return sell;
    }
};