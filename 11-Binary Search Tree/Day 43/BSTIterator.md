# Binary Search Tree Iterator

## Key Idea
Instead of flattening the entire BST into an array (which takes $O(N)$ space), we can simulate the iterative inorder traversal using a stack. The stack will only store the nodes for the left spine, taking $O(H)$ space.

## Pattern
Binary Search Tree / Iterator / Iterative Inorder

## Approach
- **Constructor**: Initialize the iterator with the root. Call a helper function `pushAll(root)` that pushes all left children onto a stack.
- **`hasNext()`**: Returns `true` if the stack is not empty.
- **`next()`**: 
  - Pop the top node from the stack. This is the next smallest element.
  - Before returning its value, if this node has a right child, call `pushAll(node->right)` to push the right child and all its left descendants onto the stack.
  - Return the popped node's data.

## Edge Case
Calling `next()` when `hasNext()` is false (should be handled by caller). Empty tree.

## Complexity
Time: O(1) amortized for `next()`, since each node is pushed and popped exactly once across all calls. O(1) for `hasNext()`.
Space: O(H) for the stack, where H is the height of the tree.

## Revision Note
Stack `myStack` -> `pushAll(node)`: while node not null, push node, `node = node->left` -> `next()`: pop, call `pushAll(popped->right)`, return popped value.
