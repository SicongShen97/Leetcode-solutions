/*
回溯：横向遍历列，纵向递归行
*/
class Solution {
public:
    vector<string> chessboard;
    vector<vector<string>> res;

    bool isValid(int row, int col, int n) {
        for (int i = 0; i < row; i++) {
            if (chessboard[i][col] == 'Q') return false;
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (chessboard[i][j] == 'Q') return false;
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (chessboard[i][j] == 'Q') return false;
        }
        return true;
    }

    void backtrack(int n, int row) {
        if (row == n) {
            res.push_back(chessboard);
        }
        for (int col = 0; col < n; col++) {
            if (isValid(row, col, n)) {
                chessboard[row][col] = 'Q';
                backtrack(n, row + 1);
                chessboard[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        chessboard = vector<string>(n, string(n, '.'));
        backtrack(n, 0);
        return res;
    }
};