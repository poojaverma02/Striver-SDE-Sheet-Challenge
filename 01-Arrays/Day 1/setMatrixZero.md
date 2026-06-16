# Set Matrix Zeroes

## Key Idea
Use the first row and first column of the matrix as markers to keep track of which rows and columns need to be zeroed out.

## Pattern
Matrix Manipulation (In-place State Tracking)

## Approach
- **Check** if the first row and first column have any zeros and store this in boolean flags.
- **Traverse** the inner matrix; if `matrix[i][j] == 0`, **set** `matrix[i][0] = 0` and `matrix[0][j] = 0`.
- **Traverse** the inner matrix again; **set** cells to `0` based on the markers.
- **Zero out** the first row and column based on the boolean flags.

## Edge Case
Zero in the very first cell `matrix[0][0]`. Boolean flags ensure correct isolated handling.

## Complexity
Time: O(M * N)
Space: O(1)

## Revision Note
Mark first row/col flags -> Use 1st row/col as markers for rest -> Update rest -> Update 1st row/col.
