# Preorder Traversal

## Key Idea
Use a recursive approach to traverse the binary tree in the Root-Left-Right sequence.

## Pattern
Tree Traversal / Recursion

## Approach
- **Base Case**: If the current node is `NULL`, return to stop recursion.
- **Current Node**: Append the current node's data (`root->data`) to the result array.
- **Left Subtree**: Recursively call the function on `root->left`.
- **Right Subtree**: Recursively call the function on `root->right`.

## Edge Case
Empty tree (root is `NULL`) returns an empty array.

## Complexity
Time: O(N) where N is the number of nodes.
Space: O(H) for the recursion stack where H is the height of the tree.

## Revision Note
Root -> Left -> Right. Base case: `root == NULL`.
