# Binary Tree to Doubly Linked List

## Key Idea
We can convert a binary tree into a Doubly Linked List (DLL) in-place by performing an **in-order traversal**. During the traversal, we keep track of the previously visited node to establish the `right` and `left` pointers, mimicking `next` and `prev` respectively.

## Pattern
Tree Traversal / In-order / In-place Modification

## Approach
- **Global Pointers**: Maintain two pointers: `prev` (to track the previously visited node) and `head` (to store the start of the DLL), both initialized to `nullptr`.
- **In-order Traversal**: Create a recursive helper function `inorder(node)`.
- **Base Case**: If `node` is `nullptr`, return.
- **Left Subtree**: Recursively call `inorder(node->left)`.
- **Process Node**: 
  - If `prev` is `nullptr`, this is the first node visited (the leftmost node), so set `head = node`.
  - If `prev` is not `nullptr`, link them together: `prev->right = node` and `node->left = prev`.
  - Update `prev` to point to the current `node`.
- **Right Subtree**: Recursively call `inorder(node->right)`.

## Edge Case
Empty tree. Skewed tree.

## Complexity
Time: O(N) as each node in the tree is visited exactly once.
Space: O(H) for the recursion stack where H is the height of the tree.

## Revision Note
In-order traversal. Keep a global `prev`. If `prev == null`, set `head`. Else link `prev->right = curr` and `curr->left = prev`. Update `prev = curr`.
