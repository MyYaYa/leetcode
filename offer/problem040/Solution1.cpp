class Solution {
public:
    int MaxValueGift(vector<vector<int>> matrix) {
        if (matrix.empty()) return 0;
        int row = matrix.size();
        if (matrix[0].empty())  return 0;
        int col = matrix[0].size();
        vector<int> dp(col+1, 0);
        for (int i = 1; i <= row; ++i) {
            for (int j = 1; j <= col; ++j) {
                dp[j] = max(dp[j-1], dp[j]) + matrix[i-1][j-1];
            }
        }
        return dp[col];
    }
};