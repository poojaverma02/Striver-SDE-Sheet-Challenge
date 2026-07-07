# Maximum Depth of Binary Tree

## Key Idea
The maximum depth (or height) of a binary tree is the number of nodes along the longest path from the root node down to the farthest leaf node. This can be found recursively by taking the maximum depth of the left and right subtrees.

## Pattern
Tree Traversal / DFS (Bottom-Up)

## Approach
- **DFS Function**: Create a recursive function to find the maximum depth.
- **Base Case**: If the current node is `NULL`, return `0`.
- **Recursion**: Recursively call the function to find the depth of the left subtree (`leftH`) and the right subtree (`rightH`).
- **Return**: The depth of the current node is `1` (for the node itself) plus the maximum of `leftH` and `rightH`.

## Edge Case
Empty tree (depth is 0) or single node tree (depth is 1).

## Complexity
Time: O(N) as every node is visited once.
Space: O(H) for the recursion stack where H is the height of the tree.

## Revision Note
DFS -> Base case `root == NULL` return 0 -> `leftH = maxDepth(left)`, `rightH = maxDepth(right)` -> return `1 + max(leftH, rightH)`.
