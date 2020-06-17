'''
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X

After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X

Explanation:
Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.
'''

class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """

        def helper(board, i, j, rows, cols):
            if i < 0 or i >= rows or j >= cols or j < 0 or board[i][j] != 'O':
                return
            board[i][j] = '-'
            helper(board, i+1, j, rows, cols)
            helper(board, i, j+1, rows, cols)
            helper(board, i-1, j, rows, cols)
            helper(board, i, j-1, rows, cols)

        rows = len(board)
        if rows <= 1:
            return board
        cols = len(board[0])

        for i in range(rows):
            if board[i][0] == 'O':
                helper(board, i, 0, rows, cols)
            if board[i][cols-1] == 'O':
                helper(board, i, cols-1, rows, cols)
        for i in range(cols):
            if board[0][i] == 'O':
                helper(board, 0, i, rows, cols)
            if board[rows-1][i] == 'O':
                helper(board, rows-1, i, rows, cols)

        for i in range(rows):
            for j in range(cols):
                if board[i][j] == '-': board[i][j] = 'O'
                elif board[i][j] == 'O': board[i][j] = 'X'
