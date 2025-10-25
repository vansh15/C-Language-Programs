#include <iostream>
#include <vector>
using namespace std;

bool isValid(const vector<vector<char>> &board, int row, int col, char ch) {
    for (int i = 0; i < 9; i++) {
        // Check row
        if (board[row][i] == ch) return false;

        // Check column
        if (board[i][col] == ch) return false;

        // Check 3x3 sub-box
        int subRow = 3 * (row / 3) + i / 3;
        int subCol = 3 * (col / 3) + i % 3;
        if (board[subRow][subCol] == ch) return false;
    }
    return true;
}

bool solve(vector<vector<char>> &board) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == '.') {
                for (char ch = '1'; ch <= '9'; ch++) {
                    if (isValid(board, row, col, ch)) {
                        board[row][col] = ch;

                        if (solve(board)) return true;

                        board[row][col] = '.'; // backtrack
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>> &board) {
    solve(board);
}

int main() {
    vector<vector<char>> board(9, vector<char>(9));

    cout << "Enter the Sudoku puzzle (9x9) row by row.\n";
    cout << "Use '.' for empty cells.\n\n";

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }

    solveSudoku(board);

    cout << "\nSolved Sudoku:\n";
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << ' ';
            if ((j + 1) % 3 == 0 && j != 8) cout << "| ";
        }
        cout << endl;
        if ((i + 1) % 3 == 0 && i != 8)
            cout << "------+-------+------\n";
    }

    return 0;
}

// Input:
// 5 3 . . 7 . . . .
// 6 . . 1 9 5 . . .
// . 9 8 . . . . 6 .
// 8 . . . 6 . . . 3
// 4 . . 8 . 3 . . 1
// 7 . . . 2 . . . 6
// . 6 . . . . 2 8 .
// . . . 4 1 9 . . 5
// . . . . 8 . . 7 9
// Output:
// Solved Sudoku:
// 5 3 4 | 6 7 8 | 9 1 2
// 6 7 2 | 1 9 5 | 3 4 8
// 1 9 8 | 3 4 2 | 5 6 7
// ------+-------+------
// 8 5 9 | 7 6 1 | 4 2 3
// 4 2 6 | 8 5 3 | 7 9 1
// 7 1 3 | 9 2 4 | 8 5 6
// ------+-------+------
// 9 6 1 | 5 3 7 | 2 8 4
// 2 8 7 | 4 1 9 | 6 3 5
// 3 4 5 | 2 8 6 | 1 7 9