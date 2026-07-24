# Minimum Falling Path Sum

## Key Idea
The problem asks for the minimum sum of a falling path through a 2D matrix (moving down, down-left, or down-right). We can solve this with space-optimized DP by tracking only the minimum path sums of the previous row to calculate the current row.

## Pattern
Dynamic Programming / Matrix / Space Optimization

## Approach
- **Initialization**: Create a 1D array `prev` of size $M$ (number of columns) and copy the first row of the matrix into it.
- **Iteration**: Loop through each row `i` from 1 to $N-1$:
  - Create a 1D array `cur` of size $M$.
  - Loop through each column `j` from 0 to $M-1$.
  - Calculate the cost from the three possible upward directions:
    - **Up**: `matrix[i][j] + prev[j]`.
    - **Left Diagonal**: `matrix[i][j] + prev[j-1]` (if `j > 0`, else infinity).
    - **Right Diagonal**: `matrix[i][j] + prev[j+1]` (if `j < M-1`, else infinity).
  - Store the minimum of these three values in `cur[j]`.
  - After processing the row, set `prev = cur`.
- **Return**: Iterate through the final `prev` array to find and return the minimum value.

## Edge Case
Matrix with 1 row (returns the minimum element in that row). Matrix with 1 column (only down moves are valid).

## Complexity
Time: O(N \times M) where $N$ is rows and $M$ is columns.
Space: O(M) for the `prev` and `cur` 1D arrays.

## Revision Note
Space optimized matrix DP. Base case: `prev` = first row. DP step: `cur[j] = matrix[i][j] + min(prev[j], prev[j-1], prev[j+1])` (handle boundary checks for diagonals with infinity). Result is `min(prev)`.
