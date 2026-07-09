# Construct a Binary Tree from Postorder and Inorder Traversal

## Key Idea
The last element in the postorder traversal is always the root. By finding this root in the inorder traversal, we can determine the sizes of the left and right subtrees and recursively build the tree.

## Pattern
Tree Construction / Divide and Conquer

## Approach
- **Hash Map**: Create a hash map storing the elements of the inorder traversal and their corresponding indices for $O(1)$ lookup time.
- **Recursive Helper**: Pass the current bounds of the inorder array (`inStart`, `inEnd`) and postorder array (`postStart`, `postEnd`).
- **Base Case**: If `inStart > inEnd` or `postStart > postEnd`, return `nullptr`.
- **Root Node**: Create the root node using the value at `postorder[postEnd]`.
- **Subtree Sizes**: Find the root's index in the inorder map (`rootIndexInorder`). The number of elements in the left subtree is `leftSubtreeSize = rootIndexInorder - inStart`.
- **Recursion**: 
  - Left child is built from the left portion of the inorder array and the corresponding left portion of the postorder array.
  - Right child is built from the right portion of the inorder array and the right portion of the postorder array.

## Edge Case
Empty traversals or arrays of different sizes.

## Complexity
Time: O(N) since every node is processed once and map lookup takes O(1).
Space: O(N) for the hash map and O(H) for the recursive stack.

## Revision Note
Root is `postorder[postEnd]` -> find root in `inorder` to get `leftSubtreeSize` -> recursively build left (`postStart` to `postStart + leftSubtreeSize - 1`) and right (`postStart + leftSubtreeSize` to `postEnd - 1`).
