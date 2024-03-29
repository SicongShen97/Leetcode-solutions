/*
回溯：横向遍历列和行
*/
class Solution {
public:
    bool isValid(const vector<vector<char>>& board, int row, int col, char num) {
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == num) return false;
        }
        for (int j = 0; j < 9; j++) {
            if (board[row][j] == num) return false;
        }
        int block_row = row / 3;
        int block_col = col / 3;
        for (int i = block_row * 3; i < block_row * 3 + 3; i++) {
            for (int j = block_col * 3; j < block_col * 3 + 3; j++) {
                if (board[i][j] == num) return false;
            }
        }
        return true;
    }

    bool backtrack(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.') {
                    for (char num = '1'; num <= '9'; num++) {
                        if (isValid(board, row, col, num)) {
                            board[row][col] = num;
                            if (backtrack(board)) return true;
                            board[row][col] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board);
    }
};