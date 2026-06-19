# Rat in a Maze

## Key Idea
Use recursive backtracking to explore all valid paths (Down, Left, Right, Up) from the start cell to the destination, marking cells as visited to prevent cycles.

## Pattern
Recursion / Backtracking

## Approach
- **Base Case**: If destination cell `(n-1, n-1)` is reached, add the current `path` string to the result.
- **Explore Paths**: Try moves in lexicographical order ('D', 'L', 'R', 'U') so the final result is sorted.
- **Check Validity**: For each move, verify it stays within bounds, lands on an open cell (`1`), and isn't already `visited`.
- **Recurse**: Mark the cell as visited, append the move character to `path`, and recurse.
- **Backtrack**: Remove the character and unmark the cell to explore other paths.

## Edge Case
Start or destination cell is blocked (`0`), or no valid path exists.

## Complexity
Time: O(4^(N^2))
Space: O(N^2)

## Revision Note
Lexicographical moves (D, L, R, U) -> check bounds, `grid == 1`, `!visited` -> mark visited, push move -> recurse -> backtrack.
