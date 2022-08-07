'''
回溯：横向遍历列，纵向递归行
'''


class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        chessboard = [['.'] * n for _ in range(n)]
        res = []

        def isValid(row, col, n):
            nonlocal chessboard, res
            for i in range(row):
                if chessboard[i][col] == 'Q':
                    return False
            i = row - 1
            j = col - 1
            while i >= 0 and j >= 0:
                if chessboard[i][j] == 'Q':
                    return False
                i -= 1
                j -= 1
            i = row - 1
            j = col + 1
            while i >= 0 and j < n:
                if chessboard[i][j] == 'Q':
                    return False
                i -= 1
                j += 1
            return True

        def backtrack(n, row):
            nonlocal chessboard, res
            if row == n:
                temp = [''.join(s) for s in chessboard]
                res.append(temp)
                return
            for col in range(n):
                if isValid(row, col, n):
                    chessboard[row][col] = 'Q'
                    backtrack(n, row + 1)
                    chessboard[row][col] = '.'

        backtrack(n, 0)
        return res
