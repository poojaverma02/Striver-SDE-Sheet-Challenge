# Merge Two Sorted Arrays

## Key Idea
Start merging from the end of both arrays to utilize the free space at the back of `nums1`, avoiding any shifting of elements.

## Pattern
Two Pointers (Reverse Traversal)

## Approach
- **Initialize** pointers `i` at the end of valid `nums1`, `j` at the end of `nums2`, and `ind` at the end of `nums1`'s total capacity.
- **Compare** elements at `i` and `j`.
- **Place** the larger element at `ind` and decrement the respective pointers.
- **Repeat** until `nums2` is fully placed.

## Edge Case
`nums1` has no valid elements initially. Loop handles it gracefully as `i < 0`.

## Complexity
Time: O(N + M)
Space: O(1)

## Revision Note
Two pointers from the back -> Place largest at the very end -> Decrement.
