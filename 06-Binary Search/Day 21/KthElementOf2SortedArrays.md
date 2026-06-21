# K-th Element of Two Sorted Arrays

## Key Idea
Apply binary search on the smaller array to partition the arrays such that the total elements on the left side equal `k`, ensuring valid boundaries.

## Pattern
Binary Search on Answer / Partitioning

## Approach
- **Ensure** the first array `a` is the smaller one.
- **Set** search bounds: `low = max(0, k - n)` and `high = min(k, m)`.
- **Partition**: Calculate `mid1` for `a` and `mid2 = k - mid1` for `b`.
- **Check Valid Partition**: If `l1 <= r2` and `l2 <= r1`, return `max(l1, l2)`.
- **Adjust Boundaries**: If `l1 > r2`, move left (`high = mid1 - 1`). Otherwise, move right (`low = mid1 + 1`).

## Edge Case
`k` equals 1 or `k` equals the sum of lengths of both arrays.

## Complexity
Time: O(log(min(M, N)))
Space: O(1)

## Revision Note
Binary search on smaller array -> `low = max(0, k-n)`, `high = min(k, m)` -> `l1 <= r2 && l2 <= r1` -> `return max(l1, l2)`.
