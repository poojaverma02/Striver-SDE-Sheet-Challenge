# Lowest Common Ancestor in Binary Tree

## Key Idea
Use a recursive DFS traversal to search for the two target nodes `p` and `q`. The lowest common ancestor is the node where `p` is found in one subtree and `q` is found in the other, or one of the nodes itself if it's an ancestor of the other.

## Pattern
Tree Traversal / DFS (Bottom-Up)

## Approach
- **Base Case**: If the current node is `NULL`, or if it matches either `p` or `q`, return the current node.
- **Search Left**: Recursively search for `p` and `q` in the left subtree.
- **Search Right**: Recursively search for `p` and `q` in the right subtree.
- **Evaluate**: 
  - If the left search returns `NULL`, the answer must be in the right subtree (return `right`).
  - If the right search returns `NULL`, the answer must be in the left subtree (return `left`).
  - If both searches return a non-`NULL` node, the current node is the LCA (return `root`).

## Edge Case
`p` or `q` is not present in the tree (though usually guaranteed to exist). One node is a descendant of the other.

## Complexity
Time: O(N) as each node is visited at most once.
Space: O(H) for the recursion stack where H is the height of the tree.

## Revision Note
Base case: `if (!root || root == p || root == q) return root;` -> search left and right -> if both found return `root` -> else return the non-null result.
