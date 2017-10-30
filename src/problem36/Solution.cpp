class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int len = board.size();
        vector<vector<char>> v1(9,vector<char>(9));
        vector<vector<char>> v2(9,vector<char>(9));
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                if (board[i][j] != '.') {
                    auto p = find(board[i].begin(), board[i].end(), board[i][j]);
                    if (p < board[i].begin()+j)
                        return false;
                    if (find(v1[j].begin(), v1[j].end(), board[i][j]) != v1[j].end()) {
                        return false;
                    } else {
                        v1[j].push_back(board[i][j]);
                    }
                    if (find(v2[(i/3)*3+(j/3)].begin(), v2[(i/3)*3+(j/3)].end(), board[i][j]) != v2[(i/3)*3+(j/3)].end()){
                        return false;
                    } else {
                        v2[(i / 3) * 3 + (j / 3)].push_back((board[i][j]));
                    }
                }
            }
        }
        return true;
    }
};