// T.C: O(4^(N^2))
// S.C: O(N^2)
// Question Link: https://takeuforward.org/plus/dsa/problems/rat-in-a-maze?source=strivers-sde-sheet

class Solution{
    public:
    // Recursive backtracking function that explores all paths from
    // the current cell (row, col) toward the destination (n-1, n-1).
    // `path` accumulates the moves made so far ('D','L','R','U').
    void solve(int row, int col, vector<vector<int>>& grid, int n,
               vector<vector<int>>& visited, string& path,
               vector<string>& result) {
        // Base case: reached the destination cell.
        // Save the path built so far and stop exploring further from here.
        if (row == n - 1 && col == n - 1) {
            result.push_back(path);
            return;
        }

        // Try moves in alphabetical order (D, L, R, U) so the final
        // result list comes out lexicographically sorted without
        // needing a separate sort step at the end.

        // Move Down: (row+1, col)
        if (row + 1 < n && grid[row + 1][col] == 1 && visited[row + 1][col] == 0) {
            visited[row + 1][col] = 1;
            path.push_back('D');

            solve(row + 1, col, grid, n, visited, path, result);

            path.pop_back();
            visited[row + 1][col] = 0;
        }

        // Move Left: (row, col-1)
        if (col - 1 >= 0 && grid[row][col - 1] == 1 && visited[row][col - 1] == 0) {
            visited[row][col - 1] = 1;
            path.push_back('L');

            solve(row, col - 1, grid, n, visited, path, result);

            path.pop_back();
            visited[row][col - 1] = 0;
        }

        // Move Right: (row, col+1)
        if (col + 1 < n && grid[row][col + 1] == 1 && visited[row][col + 1] == 0) {
            visited[row][col + 1] = 1;
            path.push_back('R');

            solve(row, col + 1, grid, n, visited, path, result);

            path.pop_back();
            visited[row][col + 1] = 0;
        }

        // Move Up: (row-1, col)
        if (row - 1 >= 0 && grid[row - 1][col] == 1 && visited[row - 1][col] == 0) {
            visited[row - 1][col] = 1;
            path.push_back('U');

            solve(row - 1, col, grid, n, visited, path, result);

            path.pop_back();
            visited[row - 1][col] = 0;
        }
    }

    vector<string> findPath(vector<vector<int> > &grid) {
        int n = grid.size();
        vector<string> result;

        // If the starting cell itself is blocked, the rat can't move
        // at all, so there are no valid paths.
        if (n == 0 || grid[0][0] == 0) return result;

        // Tracks which cells are part of the current path being
        // explored, to ensure no cell is revisited within one path.
        vector<vector<int>> visited(n, vector<int>(n, 0));

        // The starting cell counts as visited from the beginning.
        visited[0][0] = 1;

        // Accumulates the sequence of moves for the current path
        // being explored.
        string path = "";

        solve(0, 0, grid, n, visited, path, result);
        return result;
    }
};