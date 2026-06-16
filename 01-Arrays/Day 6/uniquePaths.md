# Grid Unique Paths

## Key Idea
Use Dynamic Programming with space optimization. The number of unique paths to a cell `(i, j)` is the sum of paths from `(i-1, j)` (up) and `(i, j-1)` (left).

## Pattern
Dynamic Programming (Space Optimized)

## Approach
- **Initialize** a `prev` row initialized to `0`.
- **Iterate** over `m` rows and `n` columns.
- **Calculate** paths for the current cell as `up + left`. The base case `(0, 0)` is initialized to `1`.
- **Update** `prev` to `temp` after completing a row.
- **Return** the value at `prev[n-1]`.

## Edge Case
A 1x1 grid should correctly return 1. Out of bounds accesses are handled by initializing default counts to 0.

## Complexity
Time: O(M * N)
Space: O(N)

## Revision Note
Current state only depends on the previous row `prev` and current row `temp`. DP space optimization from O(M*N) to O(N).