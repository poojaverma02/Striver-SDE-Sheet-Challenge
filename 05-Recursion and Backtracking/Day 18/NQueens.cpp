// T.C: O(n!)
// S.C: O(n) 
// Question Link: https://takeuforward.org/plus/dsa/problems/n-queen?source=strivers-sde-sheet

class Solution {
public:
    // Check if it's safe to place a queen at board[row][col]
    bool isSafe(vector<string>& board, int row, int col) {
        int r = row, c = col;

        // Check for upper left diagonal
        while (r >= 0 && c >= 0) {
            if (board[r][c] == 'Q') return false;
            r--;
            c--;
        }

        // Reset to the original position
        r = row;
        c = col;

        // Check for top
        while (r >= 0) {
            if (board[r][c] == 'Q') return false;
            r--;
        }

        // Reset to the original position
        r = row;
        c = col;

        // Check for top right diagonal
        while (r >= 0 && c < board[0].size()) {
            if (board[r][c] == 'Q') return false;
            r--;
            c++;
        }

        // If no queens are found, it's safe
        return true;
    }

    // Function to place queens on the board
    void func(int row, vector<vector<string>>& ans, vector<string>& board) {
        // If all columns are filled, add the solution to the answer
        if (row == board.size()) {
            ans.push_back(board);
            return;
        }

        // Try placing a queen in each column for the current row
        for (int col = 0; col < board[0].size();  col++) {
            // Check if it's safe to place a queen
            if (isSafe(board, row, col)) {
                // Place the queen
                board[row][col] = 'Q';

                // Recursively place queens in the next rows
                func(row + 1, ans, board);

                // Remove the queen and backtrack
                board[row][col] = '.';
            }
        }
    }

    // Solve the N-Queens problem
    vector<vector<string>> solveNQueens(int n) {
        // List to store the solutions
        vector<vector<string>> ans;
        // Initialize the board with empty cells
        vector<string> board(n, string(n, '.'));

        // Start placing queens from the first column
        func(0, ans, board);
        return ans;
    }
};