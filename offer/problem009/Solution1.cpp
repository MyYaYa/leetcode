class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        bool* visited = new bool[rows * cols];
        memset(visited, 0, rows*cols);
        int count = backtrack(threshold, rows, cols, 0, 0, visited);
        delete[] visited;
        return count;
    }
    
    int backtrack(int threshold, int rows, int cols, int row, int col, bool* visited) {
        int count = 0;
        if (row < 0 || row >= rows || col < 0 || col > cols || visited[row*cols+col]) {
            return count;
        }
        if (check(threshold, row, col)) {
            visited[row*cols+col] = true;
            count = 1 + backtrack(threshold, rows, cols, row+1, col, visited) +
                        backtrack(threshold, rows, cols, row-1, col, visited) +
                        backtrack(threshold, rows, cols, row, col+1, visited) +
                        backtrack(threshold, rows, cols, row, col-1, visited);
        }
        return count;
    }
    
    bool check(int threshold, int row, int col) {
        return getDigitalNum(row) + getDigitalNum(col) <= threshold;
    }
    
    int getDigitalNum(int number) {
        int sum = 0;
        while (number) {
            sum += number % 10;
            number /= 10;
        }
        return sum;
    }
};