# Check for Balanced Binary Tree

## Key Idea
A binary tree is balanced if the heights of the two child subtrees of any node never differ by more than 1. We can modify a standard height-calculating DFS function to return `-1` if it detects an imbalance.

## Pattern
Tree Traversal / DFS (Bottom-Up)

## Approach
- **DFS Function**: Create a recursive function that returns the height of a subtree or `-1` if it is unbalanced.
- **Base Case**: If the node is `NULL`, return `0`.
- **Recursion**: Get the height of the left subtree. If it returns `-1`, propagate the `-1` upwards immediately. Do the same for the right subtree.
- **Check Balance**: If `abs(leftH - rightH) > 1`, the current node is unbalanced. Return `-1`.
- **Return Height**: If balanced, return `1 + max(leftH, rightH)`.

## Edge Case
Empty tree (considered balanced). Deeply skewed tree (unbalanced).

## Complexity
Time: O(N) as every node is visited once and we short-circuit upon finding an imbalance.
Space: O(H) for the recursion stack where H is the height of the tree.

## Revision Note
DFS returns height or `-1` -> if `abs(leftH - rightH) > 1` return `-1` -> propagate `-1` up -> `isBalanced` is true if `dfsHeight != -1`.
