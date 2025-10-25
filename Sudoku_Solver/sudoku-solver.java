import java.util.*;

public class SudokuSolver {

    public static boolean isValid(char[][] board, int row, int col, char ch) {
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

    public static boolean solve(char[][] board) {
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

    public static void solveSudoku(char[][] board) {
        solve(board);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char[][] board = new char[9][9];

        System.out.println("Enter Sudoku puzzle row by row (use '.' for empty cells):");

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                board[i][j] = sc.next().charAt(0);
            }
        }

        solveSudoku(board);

        System.out.println("\nSolved Sudoku:");
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                System.out.print(board[i][j] + " ");
                if ((j + 1) % 3 == 0 && j != 8)
                    System.out.print("| ");
            }
            System.out.println();
            if ((i + 1) % 3 == 0 && i != 8)
                System.out.println("------+-------+------");
        }

        sc.close();
    }
}
