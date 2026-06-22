# Single Element in a Sorted Array

## Key Idea
Use binary search and leverage the index pattern of pairs to find the single element: before the single element, pairs start at even indices; after it, pairs start at odd indices.

## Pattern
Modified Binary Search

## Approach
- **Handle** edge cases for arrays of size 1 and boundary elements first.
- **Binary Search** the inner elements. If `nums[mid]` doesn't match its neighbors, return `nums[mid]`.
- **Check Pattern**: If `mid` is odd and matches `mid - 1`, or `mid` is even and matches `mid + 1`, the pattern is unbroken, so the single element is to the right (`low = mid + 1`).
- **Otherwise**, the pattern is broken, so search left (`high = mid - 1`).

## Edge Case
Single element is at the very beginning or end of the array.

## Complexity
Time: O(logN)
Space: O(1)

## Revision Note
Check boundaries -> if `even & matches next` OR `odd & matches prev`, pattern is fine -> search right (`low = mid + 1`) -> else search left.
