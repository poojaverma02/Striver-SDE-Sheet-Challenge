# Children Sum Property in Binary Tree

## Key Idea
A tree satisfies the children sum property if, for every node, its value is equal to the sum of the values of its left and right children (considering NULL children as 0).

## Pattern
Tree Traversal / DFS

## Approach
- **Base Case 1**: If the node is `NULL`, return `true`.
- **Base Case 2**: If the node is a leaf (both children are `NULL`), return `true`.
- **Calculate Sum**: Safely extract the value of the left child (`leftVal`) and the right child (`rightVal`). Treat `NULL` children as having a value of `0`.
- **Verify**: Check if the current node's value equals `leftVal + rightVal`.
- **Recursion**: If the current node satisfies the property, recursively verify that the left subtree and the right subtree also satisfy the property using the logical `&&` operator.

## Edge Case
Empty tree or a tree with just a root node.

## Complexity
Time: O(N) since every node is visited once.
Space: O(H) for the recursion stack where H is the height of the tree.

## Revision Note
Base case: `!root` or leaf -> `leftVal = root->left ? root->left->val : 0`, `rightVal = root->right ? root->right->val : 0` -> return `root->val == leftVal + rightVal && dfs(left) && dfs(right)`.
