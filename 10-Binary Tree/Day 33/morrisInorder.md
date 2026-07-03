# Morris Inorder Traversal

## Key Idea
Traverse the tree in inorder without using recursion or a stack by creating temporary threaded links from the inorder predecessors back to the current node.

## Pattern
Morris Traversal / Threaded Binary Tree

## Approach
- **Initialize**: Start `cur` at the `root`.
- **No Left Child**: If `cur->left` is `NULL`, record `cur->data` and move to `cur->right`.
- **Has Left Child**: Find the inorder predecessor (rightmost node in the left subtree).
  - If its `right` is `NULL` (no thread), link it to `cur` (`prev->right = cur`) and move `cur` to `cur->left`.
  - If its `right` points to `cur` (thread exists), the left subtree is fully visited. Remove the thread (`prev->right = NULL`), record `cur->data`, and move `cur` to `cur->right`.

## Edge Case
Empty tree or a completely skewed tree.

## Complexity
Time: O(2N) amortized, as each edge is traversed at most 3 times.
Space: O(1) auxiliary space (no recursion stack).

## Revision Note
If `!cur->left`: visit, go right. Else find predecessor `prev`. If `!prev->right`: create thread `prev->right = cur`, go left. If `prev->right == cur`: remove thread, visit, go right.
