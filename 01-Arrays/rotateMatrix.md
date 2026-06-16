# Rotate Matrix by 90 Degrees

## Key Idea
To rotate a matrix 90 degrees clockwise in place, first transpose the matrix, then reverse every individual row.

## Pattern
Matrix Manipulation

## Approach
- **Transpose** the matrix by swapping `matrix[i][j]` with `matrix[j][i]` for `j < i`.
- **Iterate** through each row of the transposed matrix.
- **Reverse** each row using `std::reverse`.

## Edge Case
1x1 matrix. The loops just bypass the operations correctly without errors.

## Complexity
Time: O(N^2)
Space: O(1)

## Revision Note
Transpose (swap `(i,j)` with `(j,i)`) -> Reverse each row.
