# Construct Binary Search Tree from Preorder Traversal

## Key Idea
In a preorder traversal of a BST, the first element is the root. Subsequent elements smaller than the root form the left subtree, and elements greater form the right subtree. We can build the tree optimally by passing an upper bound to a recursive function.

## Pattern
Binary Search Tree / Tree Construction (Recursive with Bound)

## Approach
- **Global Index**: Maintain an `index` initialized to 0, passed by reference to track the current element in the preorder array.
- **Recursive Helper**: Create a function `bstFromPreorderHelper(preorder, bound, index)`.
- **Base Case**: If `index` equals the array size OR the current element `preorder[index]` is greater than the upper `bound`, return `nullptr`.
- **Create Node**: Create a new `TreeNode` with `preorder[index]` and increment `index`.
- **Recursion**:
  - For the left subtree, the bound becomes the current node's value (`root->data`), as all left children must be smaller.
  - For the right subtree, the bound remains the same as the parent's bound.
- **Initial Call**: Call the helper with an initial bound of `INT_MAX`.

## Edge Case
Empty array. Array with a single element. Skewed trees (sorted or reverse-sorted input).

## Complexity
Time: O(N) as each element is visited once and the index is incremented.
Space: O(H) for the recursion stack, where H is the height of the BST.

## Revision Note
Helper `(preorder, bound, index)` -> `if (index == size || preorder[index] > bound) return nullptr;` -> `root = new TreeNode(preorder[index++]);` -> `root->left = dfs(..., root->data)` -> `root->right = dfs(..., bound)`.
