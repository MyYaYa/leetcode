class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        len = word.size();
        if (len == 0) {
            return false;
        }
        row = board.size();
        if (row == 0)
            return false;
        col = board[0].size();
        if (col == 0)
            return false;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (backtrack(board, word, 0, i, j))
                    return true;
            }
        }
        return false;
    }
private:
    int len;
    int row;
    int col;
    bool backtrack(vector<vector<char>>& board, string& word, int w_start, int b_row, int b_col) {
        if (w_start == len)
            return true;
        if (b_row < 0 || b_row >= row || b_col < 0 || b_col >= col)
            return false;
        if (board[b_row][b_col] == word[w_start]) {
            char t = board[b_row][b_col];
            board[b_row][b_col] = '\0';
            if (backtrack(board, word, w_start+1, b_row+1, b_col) || \
                   backtrack(board, word, w_start+1, b_row-1, b_col) || \
                   backtrack(board, word, w_start+1, b_row, b_col+1) || \
                   backtrack(board, word, w_start+1, b_row, b_col-1)) {
                return true;
            } else {
                board[b_row][b_col] = t;
            }
        }
        return false;
    }
};