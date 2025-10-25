def is_valid(board, row, col, ch):
    for i in range(9):
        # Check row
        if board[row][i] == ch:
            return False
        # Check column
        if board[i][col] == ch:
            return False
        # Check 3x3 sub-box
        sub_row = 3 * (row // 3) + i // 3
        sub_col = 3 * (col // 3) + i % 3
        if board[sub_row][sub_col] == ch:
            return False
    return True


def solve(board):
    for row in range(9):
        for col in range(9):
            if board[row][col] == '.':
                for ch in '123456789':
                    if is_valid(board, row, col, ch):
                        board[row][col] = ch
                        if solve(board):
                            return True
                        board[row][col] = '.'  # backtrack
                return False
    return True


def solve_sudoku(board):
    solve(board)


if __name__ == "__main__":
    print("Enter Sudoku puzzle row by row (use '.' for empty cells):")
    board = [list(input().split()) for _ in range(9)]

    solve_sudoku(board)

    print("\nSolved Sudoku:")
    for i in range(9):
        for j in range(9):
            print(board[i][j], end=' ')
            if (j + 1) % 3 == 0 and j != 8:
                print("|", end=' ')
        print()
        if (i + 1) % 3 == 0 and i != 8:
            print("------+-------+------")
