class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        if (row == 0) {
            return 0;
        }
        int col = obstacleGrid[0].size();
        if (col == 0)
            return 0;
        if (obstacleGrid[row-1][col-1]==1 || obstacleGrid[0][0]==1)
            return 0;
        vector<vector<int>> dp(row+1, vector<int>(col+1, 0));
        dp[0][1]=1;
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                if (obstacleGrid[i-1][j-1]==0) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[row][col];
    }
};