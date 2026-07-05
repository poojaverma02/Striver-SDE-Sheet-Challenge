# Right View of Binary Tree

## Key Idea
Use a modified DFS traversal (Root $\rightarrow$ Right $\rightarrow$ Left) to keep track of the current level. The first node visited at any depth is the rightmost node for that level.

## Pattern
Tree Traversal / DFS

## Approach
- **DFS Function**: Pass the `root`, current `level` (starts at 0), and the result array by reference.
- **Base Case**: If `root == NULL`, return.
- **Record**: If the result array size is equal to the current `level`, this is the first time we are reaching this level. Append `root->data`.
- **Traverse**: Call the DFS function recursively for the right child first (`level + 1`), then the left child (`level + 1`).

## Edge Case
Empty tree or left-skewed tree where left nodes act as the right boundary.

## Complexity
Time: O(N) where N is the number of nodes.
Space: O(H) for the recursion stack where H is the height of the tree.

## Revision Note
DFS(node, level, ans) -> if `ans.size() == level`, push `node->data` -> DFS(right, level+1) -> DFS(left, level+1).
