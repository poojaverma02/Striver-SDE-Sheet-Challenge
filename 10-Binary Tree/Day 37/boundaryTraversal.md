# Boundary Traversal of Binary Tree

## Key Idea
The boundary traversal of a binary tree consists of three parts: the left boundary (excluding leaves), the leaf nodes (from left to right), and the right boundary in reverse order (excluding leaves).

## Pattern
Tree Traversal / Multiple Passes

## Approach
- **Initialize**: If the tree is empty, return an empty array. If the root is not a leaf, add it to the result array first.
- **Left Boundary**: Traverse from `root->left`. If it's not a leaf, add it to the result. Move left if a left child exists; otherwise, move right. Stop when a leaf is reached.
- **Leaves**: Use a standard DFS to find and add all leaf nodes from left to right.
- **Right Boundary**: Traverse from `root->right`. If it's not a leaf, add it to a temporary array. Move right if a right child exists; otherwise, move left. Stop when a leaf is reached. Finally, add the nodes from the temporary array to the result in reverse order.

## Edge Case
Empty tree, or a tree with only a root node. Skewed trees.

## Complexity
Time: O(N) where N is the number of nodes (each node is visited a constant number of times).
Space: O(N) for the recursion stack during leaf collection and storing the result.

## Revision Note
Add root (if not leaf) -> collect left boundary (prefer left child) -> collect all leaves (DFS) -> collect right boundary (prefer right child) and reverse it before adding.
