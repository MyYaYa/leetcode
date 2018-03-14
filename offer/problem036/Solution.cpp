class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if (array.empty())  return 0;
        int len = array.size();
        vector<int> dp(len, 0);
        dp[0] = array[0];
        for (int i = 1; i < len; ++i) {
            if (dp[i-1] <= 0)
                dp[i] = array[i];
            else
                dp[i] = dp[i-1] + array[i];
        }
        return *max_element(dp.begin(), dp.end());
        // int greatest = dp[0];
        // for (int j = 1; j < len; ++j) {
        //    greatest = max(greatest, dp[j]);
        // }
        // return greatest;
    }
};