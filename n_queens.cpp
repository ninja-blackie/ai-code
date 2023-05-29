#include <iostream>
#include <vector>

using namespace std;

// Function to check if a queen can be placed at a given position on the board
bool isSafe(vector<vector<int>>& board, int row, int col, int n) {
    // Check if there is a queen in the same column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    // Check if there is a queen in the upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check if there is a queen in the upper right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

// Recursive function to solve the N-Queens problem using backtracking and branch and bound
bool solveNQueensUtil(vector<vector<int>>& board, int row, int n) {
    // Base case: All queens have been placed
    if (row == n) {
        return true;
    }

    for (int col = 0; col < n; col++) {
        // Check if the current position is safe to place a queen
        if (isSafe(board, row, col, n)) {
            // Place the queen at the current position
            board[row][col] = 1;

            // Recursive call to place the remaining queens
            if (solveNQueensUtil(board, row + 1, n)) {
                return true;
            }

            // Backtrack: Remove the queen from the current position
            board[row][col] = 0;
        }
    }

    return false;
}

// Function to solve the N-Queens problem using backtracking and branch and bound
void solveNQueens(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));

    if (solveNQueensUtil(board, 0, n)) {
        // Print the solution
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution exists." << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of queens (board size): ";
    cin >> n;

    solveNQueens(n);

    return 0;
}
