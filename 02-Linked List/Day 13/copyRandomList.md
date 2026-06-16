# Clone a Linked List with Random and Next Pointer

## Key Idea
Insert copied nodes right next to their original nodes, then connect the random pointers, and finally separate the original and copied lists.

## Pattern
In-place Modification / Three Passes

## Approach
- **Insert** copy nodes in between original nodes.
- **Connect** random pointers for the copied nodes using the adjacent original nodes.
- **Separate** the list into the original list and the deep copy list using a dummy node.

## Edge Case
Empty linked list.

## Complexity
Time: O(3N)
Space: O(N)

## Revision Note
Insert deep copy nodes right after original -> set random pointers `copy->random = temp->random->next` -> detach lists.
