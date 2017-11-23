class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if (row == 0)
            return false;
        int col = matrix[0].size();
        if (col == 0)
            return false;
        int i = 0;
        while (i < row && matrix[i][0] <= target) {
            i++;
        }
        if (i > 0)
            i--;
        for (int j = 0; j < col; j++) {
            if (matrix[i][j] == target)
                return true;
        }
        return false;
    }
};
