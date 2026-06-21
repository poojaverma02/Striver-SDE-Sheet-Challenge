# Search in Rotated Sorted Array I

## Key Idea
Use binary search by always checking which half of the array (left or right) is sorted, and then determining if the target lies within that sorted half.

## Pattern
Modified Binary Search

## Approach
- **Initialize** `low` and `high` pointers.
- **Find** the `mid` element. If it matches the target, return `mid`.
- **Check** if the left half `[low..mid]` is sorted. If so, check if the target is in this range to update `high`, otherwise search the right half.
- **Else**, the right half `[mid..high]` is sorted. If the target is in this range, update `low`, otherwise search the left half.

## Edge Case
Array is not rotated, or the array has only 1 or 2 elements.

## Complexity
Time: O(logN)
Space: O(1)

## Revision Note
Find sorted half -> if `nums[low] <= nums[mid]` (left is sorted), check if target is in range, update `low`/`high` -> else right is sorted, repeat check.
