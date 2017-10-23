// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int len = prices.size();
//         if (len < 2)
//             return 0;
//         priority_queue<int> q;
//         int last = prices[0];
//         int min_v = prices[0];
//         int profit = 0;
//         for (int i = 1; i < len; i++) {
//             if (prices[i] <= last) {
//                 q.push(profit);
//                 profit = 0;
//                 min_v = prices[i];
//             }
//             if (prices[i] > min_v) {
//                 profit = max(prices[i] - min_v, profit);
//             }
//             last = prices[i];
//         }
//         q.push(profit);

//         int v1=0, v2=0;
//         if (!q.empty()) {
//             v1 = q.top();
//             q.pop();
//         }
//         if (!q.empty()) {
//             v2 = q.top();
//             q.pop();
//         }
//         return v1 + v2;
//     }
// };

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len < 2)
            return 0;
        int forward[len];
        int min_v = prices[0];
        forward[0] = 0;
        for (int i = 1; i < len; i++) {
            forward[i] = max(forward[i-1], prices[i]-min_v);
            min_v = min(prices[i], min_v);
        }

        int max_profit = 0;
        int back_max = 0;
        int max_v = prices[len-1];
        for (int j = len-1; j >= 0; j--) {
            back_max = max(back_max, max_v-prices[j]);
            max_v = max(prices[j], max_v);
            max_profit = max(max_profit, forward[j]+back_max);
        }
        return max_profit;
    }
};