class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> result;
        int rows = matrix.size();
        if (rows == 0) return result;
        int cols = matrix[0].size();
        if (cols == 0) return result;
        int rowBegin = 0, rowEnd = rows - 1,
            colBegin = 0, colEnd = cols - 1;
        while (rowBegin <= rowEnd && colBegin <= colEnd) {
            for (int i = colBegin; i <= colEnd; i++) {
                result.push_back(matrix[rowBegin][i]);
            }
            rowBegin++;
            for (int i = rowBegin; i <= rowEnd; i++) {
                result.push_back(matrix[i][colEnd]);
            }
            colEnd--;
            // boundary test, important!!!
            if (colBegin > colEnd || rowBegin > rowEnd)
                break;
            for (int i = colEnd; i >= colBegin; i--) {
                result.push_back(matrix[rowEnd][i]);
            }
            rowEnd--;
            for (int i = rowEnd; i >= rowBegin; i--) {
                result.push_back(matrix[i][colBegin]);
            }
            colBegin++;
        }
        return result;
    }
};