class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        bool* isPass = new bool[rows*cols];
        memset(isPass, 0, rows * cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (backtrack(matrix, rows, cols, str, i, j, 0, isPass)) {
                    return true;
                }
            }
        }
        delete[] isPass;
        return false;
    }

    bool backtrack(char* matrix, int rows, int cols, char* str,
        int row, int col, int len, bool* isPass) {
        if (str[len]=='\0')
            return true;
        if (row < 0 || row >= rows || col < 0 || col >= cols || isPass[row*cols+col])
            return false;
        if (matrix[row*cols+col]==str[len]) {
            isPass[row*cols+col] = true;
            len++;
            if (backtrack(matrix, rows, cols, str, row+1, col, len, isPass) ||
                backtrack(matrix, rows, cols, str, row-1, col, len, isPass) ||
                backtrack(matrix, rows, cols, str, row, col+1, len, isPass) ||
                backtrack(matrix, rows, cols, str, row, col-1, len, isPass)) {
                return true;
            } else {
                isPass[row*cols+col] = false;
                len--;
                return false;
            }
        } else {
            return false;
        }
    }
};