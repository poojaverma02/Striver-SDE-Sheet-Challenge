# K-th Largest Element in an Array

## Key Idea
Use the Quickselect algorithm (a variation of Quicksort) to partially sort the array and find the $K$-th largest element in expected linear time.

## Pattern
Quickselect / Divide and Conquer

## Approach
- **Initialize** `left` and `right` pointers for the search range.
- **Pivot**: Choose a random pivot index and partition the array around it, such that elements greater than the pivot are on the left.
- **Check**: The `partitionAndReturnIndex` function returns the final sorted position of the pivot.
- **Binary Search**: If `pivotIndex == k - 1`, we found the element. If `pivotIndex > k - 1`, search the left portion; otherwise, search the right portion.

## Edge Case
`K` is larger than the array size, or the array has all identical elements.

## Complexity
Time: O(N) average, O(N²) worst-case.
Space: O(1)

## Revision Note
Quickselect -> pick random pivot -> partition (larger elements left) -> if `pivotIndex == k - 1`, return -> else adjust `left`/`right`.
