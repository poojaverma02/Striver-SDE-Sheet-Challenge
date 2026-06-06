# Search a 2D Matrix

## Key Idea
Treat the 2D matrix as a virtual flattened 1D array of size `N * M`. Perform standard Binary Search, converting the 1D index back to 2D coordinates on the fly.

## Pattern
Binary Search (on 2D Array)

## Approach
- **Initialize** binary search range: `low = 0` and `high = N * M - 1`.
- **Calculate** `mid = (low + high) / 2`.
- **Map** `mid` to 2D row/column: `row = mid / M`, `col = mid % M`.
- **Check** if `mat[row][col] == target`:
  - If equal, **return** `true`.
  - If smaller, **move** `low` to `mid + 1`.
  - If larger, **move** `high` to `mid - 1`.
- **Return** `false` if the range is exhausted.

## Edge Case
Matrix containing a single element. Correctly handled by range bounds.

## Complexity
Time: O(log(N * M))
Space: O(1)

## Revision Note
Virtual 1D flat index: `row = mid / colCount`, `col = mid % colCount`. Standard Binary Search.
