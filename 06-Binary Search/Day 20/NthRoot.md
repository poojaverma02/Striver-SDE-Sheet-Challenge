# Find Nth Root of M

## Key Idea
Use binary search on the answer range `[1, M]` and apply fast exponentiation to efficiently compute `mid^N`, breaking early to prevent overflow.

## Pattern
Binary Search on Answer / Fast Exponentiation

## Approach
- **Initialize** search space with `low = 1` and `high = M`.
- **Compute** `mid^N` using binary exponentiation, returning `1` for exact match, `0` for `< M`, and `2` for `> M` (exiting early on overflow).
- **Binary Search**:
  - If `mid^N == M`, return `mid`.
  - If `mid^N < M`, move to right half (`low = mid + 1`).
  - If `mid^N > M`, move to left half (`high = mid - 1`).

## Edge Case
`M` is 1 or `N` is 1.

## Complexity
Time: O(logM * logN)
Space: O(1)

## Revision Note
Binary search `1` to `M` -> compute `mid^N` via fast exponentiation -> exit early if `ans > m` to avoid overflow -> adjust `low` or `high` based on comparison.
