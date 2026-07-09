# Flatten Binary Tree to Linked List

## Key Idea
To flatten the tree into a linked list in a preorder sequence, we can perform a reverse postorder traversal (Right $\rightarrow$ Left $\rightarrow$ Root). By keeping track of the previously processed node, we can adjust the pointers of the current node to point to it.

## Pattern
Tree Traversal / Reverse Postorder

## Approach
- **Global Pointer**: Maintain a `prev` pointer, initially set to `nullptr`, to track the last node processed.
- **Recursive Helper**: Create a recursive function that takes the current node.
- **Base Case**: If the node is `nullptr`, return.
- **Traverse Right-Left**: Recursively call the helper on the right subtree, then the left subtree. (This ensures that when we process the current node, the `prev` pointer holds the correct next node in the flattened list).
- **Rearrange Pointers**: Set the current node's `right` to point to `prev`, and its `left` to `nullptr`.
- **Update Prev**: Set `prev` to the current node.

## Edge Case
Empty tree or already skewed right tree.

## Complexity
Time: O(N) where N is the number of nodes.
Space: O(H) for the recursion stack where H is the height of the tree.

## Revision Note
Reverse Postorder (Right, Left, Root) -> `flatten(right)`, `flatten(left)` -> `root->right = prev`, `root->left = nullptr` -> `prev = root`.
