# Edit Distance

## Key Idea
The Edit Distance problem calculates the minimum number of operations (insert, delete, replace) required to convert one string into another. We can solve this using dynamic programming. To optimize space, we use two 1D arrays (`prev` and `cur`) instead of a full 2D table, as calculating the current row only requires the previous row and the current row's previous column.

## Pattern
Dynamic Programming / String / Space Optimization

## Approach
- **Initialization**: Create two arrays, `prev` and `cur`, of size $M+1$.
- **Base Case**: Initialize `prev[j] = j` for $j$ from $0$ to $M$, representing the cost of converting an empty string to a prefix of `target` of length $j$ (by inserting $j$ characters).
- **Iteration**: For $i$ from $1$ to $N$ (length of `start`):
  - Set `cur[0] = i`, the cost of converting a prefix of `start` of length $i$ to an empty string (by deleting $i$ characters).
  - For $j$ from $1$ to $M$:
    - If characters match (`start[i-1] == target[j-1]`), cost is `prev[j-1]` (no operation needed).
    - If they don't match, cost is $1 + \min(\text{insert}, \text{delete}, \text{replace}) = 1 + \min(\text{cur}[j-1], \min(\text{prev}[j], \text{prev}[j-1]))$.
  - After processing the row, swap `prev` and `cur`.
- **Return**: The answer is stored in `prev[M]`.

## Edge Case
One or both strings are empty. Both strings are identical (returns 0).

## Complexity
Time: O(N \times M) where $N$ and $M$ are lengths of the two strings.
Space: O(M) for the two 1D arrays.

## Revision Note
Space optimized DP. Base case: `prev[j] = j`. For each row: `cur[0] = i`. Match: `cur[j] = prev[j-1]`. No match: `cur[j] = 1 + min(prev[j-1], min(prev[j], cur[j-1]))`. Swap `prev` and `cur`.
