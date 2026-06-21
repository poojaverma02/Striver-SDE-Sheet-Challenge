# Median of Two Sorted Arrays

## Key Idea
Use binary search on the smaller array to partition both arrays such that the left half has the same number of elements (or one more) as the right half.

## Pattern
Binary Search on Answer / Partitioning

## Approach
- **Ensure** `arr1` is the smaller array.
- **Binary Search** `low = 0` to `high = n1`. The split points are `mid1` and `mid2 = (n1 + n2 + 1) / 2 - mid1`.
- **Check Validity**: `l1 <= r2` and `l2 <= r1`. If valid, calculate the median based on odd/even total length.
- **Adjust Boundaries**: If `l1 > r2`, move left (`high = mid1 - 1`). Otherwise, move right (`low = mid1 + 1`).

## Edge Case
One array is empty or elements of one are all greater than the other.

## Complexity
Time: O(log(min(N1, N2)))
Space: O(1)

## Revision Note
BS on smaller array -> `left = (n1 + n2 + 1)/2` -> if `l1 <= r2 && l2 <= r1` -> compute median based on parity.
