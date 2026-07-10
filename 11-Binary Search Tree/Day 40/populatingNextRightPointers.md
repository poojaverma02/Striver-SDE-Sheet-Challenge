# Populating Next Right Pointers in Each Node

## Key Idea
Instead of using a queue for level-order traversal, we can use the already established `next` pointers of the current level to populate the `next` pointers of the level directly below it.

## Pattern
Tree Traversal / Level Order (Constant Space)

## Approach
- **Initialize**: Start with a pointer `levelStart` pointing to the `root`.
- **Traverse Levels**: Loop while `levelStart->left` is not `NULL` (since it's a perfect binary tree, if a left child exists, a level exists below).
- **Traverse Current Level**: Set `curr = levelStart`. Use a nested loop to traverse nodes horizontally using their `next` pointers.
- **Connect Children**: For each `curr` node:
  - Connect its left child to its right child: `curr->left->next = curr->right`.
  - Connect its right child to the next node's left child (if `curr->next` exists): `curr->right->next = curr->next->left`.
- **Move Horizontal**: Update `curr = curr->next`.
- **Move Down**: After the inner loop finishes, move down to the next level: `levelStart = levelStart->left`.

## Edge Case
Empty tree (`root == NULL`).

## Complexity
Time: O(N) as each node is visited exactly once.
Space: O(1) auxiliary space (no queue or recursion stack used).

## Revision Note
`curr->left->next = curr->right` -> if `curr->next`, then `curr->right->next = curr->next->left` -> `curr = curr->next` -> `levelStart = levelStart->left`.
