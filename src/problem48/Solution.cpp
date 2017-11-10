class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int depth = n/2 - 1;
        for (int i = 0; i <= depth; i++) {
            for (int j = i; j < n-1-i; j++) {
                int x=i;
                int y = j;
                int temp = matrix[x][y];
                for (int k = 0; k < 3; k++) {
                    matrix[x][y] = matrix[n-1-y][x];
                    x = n-1-y;
                    y = x;
                }
                matrix[x][y] = temp;
//                int temp = matrix[i][j];
//                matrix[i][j] = matrix[n-1-j][i];
//                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
//                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
//                matrix[j][n-1-i] = temp;
            }
        }
    }
};