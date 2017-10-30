class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int len = board.size();
        bool a[len][len];
        bool b[len][len];
        bool c[len][len];
        memset(a, 0, len*len*sizeof(bool));
        memset(b, 0, len*len*sizeof(bool));
        memset(c, 0, len*len*sizeof(bool));
        for (int i=0; i<len; i++) {
            for (int j=0; j<len; j++) {
                if (board[i][j] > '0' && board[i][j] <='9') {
                    int temp = board[i][j]-'0';
                    if (a[i][temp-1]) {
                        return false;
                    } else {
                        a[i][temp-1] = true;
                    }
                    if (b[j][temp-1]) {
                        return false;
                    } else {
                        b[j][temp-1] = true;
                    }
                    if (c[(i/3)*3+(j/3)][temp-1]) {
                        return false;
                    } else {
                        c[(i/3)*3+(j/3)][temp-1] = true;
                    }
                }
            }
        }
        return true;
    }
};