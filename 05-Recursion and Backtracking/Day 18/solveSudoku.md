# Sudoku Solver

## Key Idea
Use backtracking to try placing digits `1` to `9` in every empty cell, verifying against Sudoku rules for the row, column, and 3x3 sub-box.

## Pattern
Recursion / Backtracking

## Approach
- **Traverse** the entire 9x9 board.
- **Find** an empty cell `'.'`.
- **Try** digits `1` to `9`. For each digit, check if it's safe to place using `areRulesMet`.
- **Recurse**: If safe, place the digit and recursively call `solve()`. If the recursive call returns true, the puzzle is solved.
- **Backtrack**: If not true, remove the digit `'.'` and try the next one. If no digits work, return false.

## Edge Case
Sudoku board that is already completely solved or invalid initial board.

## Complexity
Time: O(9^E)
Space: O(E)

## Revision Note
Loop rows & cols -> find `'.'` -> loop `1-9` -> `areRulesMet` (row, col, 3x3 box) -> place -> if `solve()` returns true, return true -> backtrack.
