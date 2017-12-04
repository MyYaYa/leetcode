class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if (row == 0)
            return;
        int col = matrix[0].size();
        if (col == 0)
            return;
        vector<int> rs, cs;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == 0) {
                    rs.push_back(i);
                    cs.push_back(j);
                }
            }
        }
        for (auto e : rs) {
            fill_n(matrix[e].begin(), col, 0);
        }
        for (auto e : cs) {
            for (int k = 0; k < row; k++) {
                matrix[k][e] = 0;
            }
        }
    }
};