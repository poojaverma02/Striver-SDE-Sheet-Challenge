# N-Queens

## Key Idea
Use recursion to place queens column by column in each row, backtracking whenever a queen placement violates the safety rules (no other queens in the same column, upper left diagonal, or upper right diagonal).

## Pattern
Recursion / Backtracking

## Approach
- **Initialize** an empty $N \times N$ board with `.` and a recursive function `func` starting at `row = 0`.
- **Base Case**: If `row == n`, all queens are placed successfully, add the board to the result.
- **Iterate** through all columns for the current row.
- **Check** if placing a queen is safe. If safe, place `'Q'`, recursively call `func(row + 1)`, and then backtrack by replacing `'Q'` with `'.'`.

## Edge Case
`N = 2` or `N = 3`, where no solution exists.

## Complexity
Time: O(N!)
Space: O(N)

## Revision Note
Place queen row by row -> loop cols -> `isSafe` (check 3 directions: up, up-left, up-right) -> place -> recurse -> backtrack.
