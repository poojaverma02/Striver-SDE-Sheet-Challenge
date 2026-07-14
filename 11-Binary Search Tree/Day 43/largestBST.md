# Largest BST in Binary Tree

## Key Idea
To find the largest BST subtree, we need to check if a tree is a BST from the bottom up. A tree is a BST if its left and right subtrees are BSTs, and its root value is strictly greater than the maximum of the left subtree and strictly smaller than the minimum of the right subtree.

## Pattern
Tree Traversal / DFS (Bottom-Up)

## Approach
- **Custom Return Type**: Create a struct `NodeValue` that stores `minNode`, `maxNode`, and `maxSize`.
- **DFS Helper**:
  - Base case: If `node == NULL`, return `{INT_MAX, INT_MIN, 0}` (an empty tree is a valid BST of size 0).
  - Recursively get `left` and `right` NodeValues.
  - **Validity Check**: If `left.maxNode < node->data` AND `node->data < right.minNode`, the current subtree is a valid BST.
    - Return a new `NodeValue`: `min(node->data, left.minNode)`, `max(node->data, right.maxNode)`, and `size = left.maxSize + right.maxSize + 1`.
  - **Invalid BST**: If it's not a BST, return `{INT_MIN, INT_MAX, max(left.maxSize, right.maxSize)}` to guarantee parent checks will fail, but pass up the maximum size found so far.

## Edge Case
Empty tree. Tree with all identical values.

## Complexity
Time: O(N) since every node is visited exactly once in a post-order traversal.
Space: O(H) for the recursion stack where H is the height of the tree.

## Revision Note
Post-order DFS returning `{min, max, size}` -> base case `{MAX, MIN, 0}` -> valid if `left.max < data < right.min` -> return `{min(left.min, data), max(right.max, data), left.size + right.size + 1}` -> else return `{MIN, MAX, max(left.size, right.size)}`.
