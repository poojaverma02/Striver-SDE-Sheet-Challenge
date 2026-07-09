# Check for Symmetrical Binary Trees

## Key Idea
A binary tree is symmetric if its left and right subtrees are mirror images of each other. We can check this by simultaneously traversing the left and right subtrees in opposite directions.

## Pattern
Tree Traversal / DFS

## Approach
- **Base Case**: If the `root` is `nullptr`, return `true` (an empty tree is symmetric).
- **Recursive Helper**: Pass the left child and right child to a `symmetry` function.
- **Null Checks**: If both nodes are `nullptr`, return `true`. If only one is `nullptr`, return `false`.
- **Value Check**: If the data of the two nodes do not match, return `false`.
- **Mirror Recursion**: Recursively check if the left child of the first node is a mirror of the right child of the second node (`symmetry(left->left, right->right)`), AND the right child of the first node is a mirror of the left child of the second node (`symmetry(left->right, right->left)`).

## Edge Case
Empty tree. Trees that are structurally identical but have different values.

## Complexity
Time: O(N) where N is the number of nodes (we visit each node once).
Space: O(H) for the recursion stack where H is the height of the tree.

## Revision Note
Helper takes `left` and `right` -> if both null, true; if one null, false; if values diff, false -> `return symmetry(left->left, right->right) && symmetry(left->right, right->left)`.
