# Next Permutation

## Key Idea
Find the first dipping element from the right, swap it with the next largest element to its right, and reverse the remaining suffix.

## Pattern
Array manipulation (Suffix traversal)

## Approach
- **Traverse** from right to find the first element `a[i] < a[i+1]` (the dip).
- **If no dip exists**, reverse the entire array.
- **Otherwise**, traverse from right to find the smallest element `a[j] > a[i]`.
- **Swap** `a[i]` and `a[j]`.
- **Reverse** the suffix of the array starting from `i+1`.

## Edge Case
Strictly decreasing array (e.g., `[5, 4, 3]`). Handled perfectly by reversing the entire array.

## Complexity
Time: O(N)
Space: O(1)

## Revision Note
`[2, 1, 5, 4, 3]` -> dip at `1` -> swap with `3` -> reverse `[5, 4, 1]` -> `[2, 3, 1, 4, 5]`
