'''
回溯：横向遍历列和行
'''


class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """

        def isValid(board, row, col, num):
            for i in range(9):
                if board[i][col] == num:
                    return False
            for j in range(9):
                if board[row][j] == num:
                    return False
            block_row = row // 3
            block_col = col // 3
            for i in range(3 * block_row, 3 * block_row + 3):
                for j in range(3 * block_col, 3 * block_col + 3):
                    if board[i][j] == num:
                        return False
            return True

        def backtrack(board):
            for i in range(9):
                for j in range(9):
                    if board[i][j] == '.':
                        for num in range(1, 10):
                            if isValid(board, i, j, str(num)):
                                board[i][j] = str(num)
                                if backtrack(board): return True
                                board[i][j] = '.'
                        return False
            return True

        backtrack(board)