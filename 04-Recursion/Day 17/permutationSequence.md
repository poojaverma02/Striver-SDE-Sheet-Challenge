# Permutation Sequence

## Key Idea
Instead of generating all permutations, mathematically determine the correct digit for each position using factorials and a 0-based `k` index.

## Pattern
Math / Combinatorics

## Approach
- **Initialize** a list of numbers from `1` to `n` and precompute factorials up to `n-1`.
- **Convert** `k` to a 0-based index by doing `k--`.
- **Iterate** to build the permutation: determine the block size using `fact[i]`.
- **Find** the correct number index using `k / fact[i]`, append it to the result, and remove it from the list.
- **Update** `k = k % fact[i]` for the next position.

## Edge Case
`k = 1` or `k = n!`.

## Complexity
Time: O(n²)
Space: O(n)

## Revision Note
Precompute factorials -> `k--` -> block size = `fact[i]` -> index = `k / fact[i]` -> update `k = k % fact[i]`.
