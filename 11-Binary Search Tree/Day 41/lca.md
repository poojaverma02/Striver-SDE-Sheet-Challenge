# Lowest Common Ancestor in a BST

## Key Idea
In a Binary Search Tree, the Lowest Common Ancestor (LCA) of two nodes `p` and `q` is the first node whose value lies strictly between the values of `p` and `q` (inclusive). If both `p` and `q` are smaller than the current node, the LCA must be in the left subtree. If both are larger, it must be in the right subtree.

## Pattern
Binary Search Tree / LCA

## Approach
- **Base Case**: If `root == nullptr`, return `nullptr`.
- **Current Value**: Store the current node's data in `curr`.
- **Search Right**: If both `curr < p` and `curr < q`, it means both target nodes are in the right subtree. Recursively call `lca` on `root->right`.
- **Search Left**: If both `curr > p` and `curr > q`, both nodes are in the left subtree. Recursively call `lca` on `root->left`.
- **Found LCA**: If neither of the above conditions is met, it means `p` and `q` are on opposite sides of the current node (or one of them is the current node). This `root` is the LCA.

## Edge Case
`p` or `q` is the root node. One node is an ancestor of another.

## Complexity
Time: O(H) where H is the height of the BST. We traverse down a single path.
Space: O(H) for the recursion stack (or O(1) if implemented iteratively).

## Revision Note
If `curr < p && curr < q` -> recurse right. If `curr > p && curr > q` -> recurse left. Else -> return `root`.
