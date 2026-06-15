# Rotate a Linked List

## Key Idea
Calculate the length of the list, make it circular, and then break the circle at the appropriate node from the end.

## Pattern
Linked List Traversal / Circular Linked List

## Approach
- **Calculate** the length of the list and point the last node to the head to make it circular.
- **Compute** effective rotations `k = k % length`.
- **Traverse** to the `(length - k)`th node to find the new tail.
- **Break** the link to set the new head and terminate the list with NULL.

## Edge Case
Empty list, single node, or `k` is a multiple of length.

## Complexity
Time: O(N) + O(N - (K % N))
Space: O(1)

## Revision Note
Find length -> connect tail to head -> `k = k % length` -> move to `length - k` node -> break connection to make new head.
