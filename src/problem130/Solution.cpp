class Solution {
private:
    int row;
    int col;
public:
    void solve(vector<vector<char>>& board) {
        row = 0;
        col = 0;
        if (board.empty()) return;
        else    row = board.size();
        if (board[0].empty())   return;
        else    col = board[0].size();
        vector<vector<bool>> m(row, vector<bool>(col, false));
        for (int i = 0; i < row; i++) {
            spread(board, m, i, 0);
            spread(board, m, i, col-1);
        }
        for (int j = 0; j < col; j++) {
            spread(board, m, 0, j);
            spread(board, m, row-1, j);
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (!m[i][j])
                    board[i][j] = 'X';
            }
        }
    }

    void spread(vector<vector<char>>& board, vector<vector<bool>>& m, int i, int j) {
        if (i<0 || j<0 || i>=row || j>=col || m[i][j])
            return;
        else {
            if (board[i][j] == 'O') {
                m[i][j] = true;
                spread(board, m, i-1, j);
                spread(board, m, i+1, j);
                spread(board, m, i, j-1);
                spread(board, m, i, j+1);
            } else
                return;
        }
    }
};