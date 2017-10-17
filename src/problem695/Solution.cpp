class Solution {
public:
    vector<vector<int>> grid;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        this->grid = grid;
        int row_size = grid.size();
        if (row_size == 0) return 0;
        int column_size = grid[0].size();
        if (column_size == 0) return 0;
        int maxArea = 0;
        for (int i = 0; i < row_size; i++) {
            for (int j = 0; j < column_size; j++) {
                if (grid[i][j] == 1){
                    maxArea = max(maxArea, area(i, j));
                }
            }
        }
        return maxArea;
    }

    int area( int i, int j) {
        if (i<0 || i>=this->grid.size() || j<0 || j>=this->grid[0].size() || this->grid[i][j]==0)
            return 0;
        else {
            this->grid[i][j] = 0;
            return 1 + area(i-1,j) + area(i+1,j) + area(i,j+1) + area(i,j-1);
        }
    }
};