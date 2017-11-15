class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n,0));
        int len = n*n;
        int a = 1;
        int row_begin = 0;
        int row_end = n-1;
        int col_begin = 0;
        int col_end = n-1;

        while (a <= len) {
            for (int i = col_begin; i <= col_end; i++) {
                result[row_begin][i] = a++;
            }
            row_begin++;
            if (row_begin <= row_end) {
                for (int i = row_begin; i <= row_end; i++) {
                    result[i][col_end] = a++;
                }
            }
            col_end--;
            if (col_begin <= col_end) {
                for (int i = col_end; i >= col_begin; i--) {
                    result[row_end][i] = a++;
                }
            }
            row_end--;
            if (row_begin <= row_end) {
                for (int i = row_end; i >= row_begin; i--) {
                    result[i][col_begin] = a++;
                }
            }
            col_begin++;
        }
        return result;
    }
};