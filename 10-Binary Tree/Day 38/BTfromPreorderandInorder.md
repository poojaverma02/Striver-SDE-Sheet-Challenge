# Construct a Binary Tree from Preorder and Inorder Traversal

## Key Idea
The first element in the preorder traversal is always the root. By locating this root in the inorder traversal, we can split the tree into left and right subtrees and construct it recursively.

## Pattern
Tree Construction / Divide and Conquer

## Approach
- **Hash Map**: Create a hash map to store the elements of the inorder traversal mapped to their indices for $O(1)$ lookups.
- **Recursive Helper**: Pass the current bounds of the preorder array (`preStart`, `preEnd`) and inorder array (`inStart`, `inEnd`).
- **Base Case**: If `preStart > preEnd` or `inStart > inEnd`, return `nullptr`.
- **Root Node**: Create the root node using the value at `preorder[preStart]`.
- **Subtree Sizes**: Find the root's index in the inorder map (`inRoot`). The number of elements in the left subtree is `numsLeft = inRoot - inStart`.
- **Recursion**:
  - Left child is built from the next `numsLeft` elements in preorder and the left portion of inorder.
  - Right child is built from the remaining elements in preorder and the right portion of inorder.

## Edge Case
Empty traversals or mismatched array sizes.

## Complexity
Time: O(N) as each node is visited once and lookup is O(1).
Space: O(N) for the hash map and O(H) for the recursive stack.

## Revision Note
Root is `preorder[preStart]` -> find root in `inorder` to get `numsLeft` -> recursively build left (`preStart+1` to `preStart+numsLeft`) and right (`preStart+numsLeft+1` to `preEnd`).
