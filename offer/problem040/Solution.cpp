class Solution {
public:
    int MaxValueGift(vector<vector<int>> matrix) {
        if (matrix.empty()) return 0;
        int row = matrix.size();
        if (matrix[0].empty())  return 0;
        int col = matrix[0].size();
        vector<vector<int>> dp(row+1, vector<int>(col+1, 0));
        for (int i = 1; i <=row; ++i) {
            for (int j = 1; j <= col; ++j) {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + matrix[i-1][j-1];
            }
        }
        return dp[row][col];
    }
};

int main() {
    Solution* s = new Solution();
    vector<int> v1 = {1, 10, 3, 8};
    vector<int> v2 = {12, 2, 9, 6};
    vector<int> v3 = {5, 7, 4, 11};
    vector<int> v4 = {3, 7, 16, 5};
    vector<vector<int>> matrix;
    matrix.push_back(v1);
    matrix.push_back(v2);
    matrix.push_back(v3);
    matrix.push_back(v4);
    cout << s->MaxValueGift(matrix);
}