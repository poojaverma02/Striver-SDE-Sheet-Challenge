# Longest Common Subsequence

## Key Idea
The Longest Common Subsequence (LCS) finds the longest subsequence present in both strings. We can solve this using dynamic programming. To optimize space, instead of a full 2D DP table, we only need to keep track of the previous row (`prev`) and the current row (`cur`) since the current state only depends on the previous row and the current row's previous column.

## Pattern
Dynamic Programming / String / Space Optimization

## Approach
- **Initialization**: Create two arrays, `prev` and `cur`, both of size $M+1$ (where $M$ is the length of `str2`), initialized to 0. This also naturally covers the base cases (if either string is empty, LCS is 0).
- **Nested Loops**: Iterate through `str1` (1 to $N$) and `str2` (1 to $M$).
- **State Transition**:
  - If characters match (`str1[ind1 - 1] == str2[ind2 - 1]`), we found a common character. The length becomes $1 +$ the value from the diagonal (i.e., $1 + \text{prev}[ind2 - 1]$).
  - If characters do not match, take the maximum of excluding the current character from `str1` (i.e., `prev[ind2]`) or excluding it from `str2` (i.e., `cur[ind2 - 1]`).
- **Update**: After processing each row (each character of `str1`), copy `cur` to `prev`.
- **Return**: The answer is stored in `prev[M]`.

## Edge Case
One or both strings are empty. No common characters between the strings.

## Complexity
Time: O(N \times M) where $N$ and $M$ are lengths of the two strings.
Space: O(M) because we only use two 1D arrays of size $M+1$.

## Revision Note
Space optimized DP for LCS. Match: `cur[j] = 1 + prev[j-1]`. No match: `cur[j] = max(prev[j], cur[j-1])`. Update `prev = cur` after the inner loop.
