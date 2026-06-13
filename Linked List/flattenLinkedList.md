# Flatten a Linked List

## Key Idea
Recursively flatten the rest of the linked list and merge the current list with the flattened list using a dummy node.

## Pattern
Recursion / Merge Two Sorted Lists

## Approach
- **Base Case:** If `head` is NULL or `head->next` is NULL, return `head`.
- **Recurse** to flatten `head->next`.
- **Merge** the current list (`head`) with the recursively flattened list based on values using a dummy node.
- **Return** the merged list via child pointers.

## Edge Case
Empty list or list with a single node.

## Complexity
Time: O(M × N²)
Space: O(N)

## Revision Note
Recurse to the end -> `merge(head, flattenLinkedList(head->next))` -> link sorted values using child pointers.
