class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (k == 0) {
            return 0;
        }
        int len = prices.size();
        if (len < 2) {
            return 0;
        }
        if (k >= len/2) {
            return find_max(prices);
        }
        //int gain[k+1][len];
//        for (int i = 0; i < k+1; i++) {
//            fill_n(gain[i], len, 0);
//        }
        //memset(gain, 0, sizeof(gain[0][0])*(k+1)*len);
        vector<vector<int>> gain(k+1, vector<int>(len));
        for (int i = 1; i <= k; i++) {
            int tmp = -prices[0];
            for (int j = 1; j < len; j++) {
                gain[i][j] = max(gain[i][j-1], tmp + prices[j]);
                tmp = max(gain[i-1][j-1]-prices[j], tmp);
            }
        }
        return gain[k][len-1];
    }
    int find_max(vector<int>& prices) {
        int max_profit = 0;
        for (int i = 0; i<prices.size()-1; i++) {
            max_profit += max(0, prices[i+1]-prices[i]);
        }
        return max_profit;
    }
};