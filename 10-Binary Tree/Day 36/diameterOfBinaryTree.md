# Diameter of Binary Tree

## Key Idea
The diameter of a binary tree is the length of the longest path between any two nodes. This path may or may not pass through the root. We can compute the diameter efficiently by piggybacking on the height calculation of the tree.

## Pattern
Tree Traversal / DFS (Bottom-Up)

## Approach
- **DFS Function**: Create a recursive function that returns the height of a subtree and takes a reference to a `diameter` variable.
- **Base Case**: If the node is `NULL`, return `0`.
- **Recursion**: Recursively find the height of the left and right subtrees.
- **Update Diameter**: At each node, the longest path passing through it is `leftH + rightH`. Update `diameter = max(diameter, leftH + rightH)`.
- **Return Height**: Return `1 + max(leftH, rightH)` to pass the height up to the parent node.

## Edge Case
Empty tree or tree with a single node (diameter is 0).

## Complexity
Time: O(N) as every node is visited once.
Space: O(H) for the recursion stack where H is the height of the tree.

## Revision Note
DFS returns height -> `diameter = max(diameter, leftH + rightH)` -> return `1 + max(leftH, rightH)`.
