# Maximum Path Sum

## Key Idea
The maximum path sum can pass through any node. For a given node, the maximum path passing through it is its value plus the maximum *positive* path sums from its left and right children.

## Pattern
Tree Traversal / DFS (Bottom-Up)

## Approach
- **DFS Function**: Use a recursive function that returns the maximum path sum starting from the current node and going downwards (to either the left or right child, but not both). Pass a `maxi` variable by reference to track the overall maximum path sum.
- **Base Case**: If the node is `NULL`, return `0`.
- **Ignore Negative Paths**: Recursively calculate the maximum paths for the left and right children. If a child's path sum is negative, ignore it by taking `max(0, childPathSum)`.
- **Update Maximum**: Update `maxi` with the maximum path *through* the current node: `maxi = max(maxi, leftMaxPath + rightMaxPath + root->data)`.
- **Return Value**: Return the maximum path extending from the current node: `root->data + max(leftMaxPath, rightMaxPath)`.

## Edge Case
Trees with all negative node values.

## Complexity
Time: O(N) since each node is visited once.
Space: O(H) for the recursion stack, where H is the height of the tree.

## Revision Note
DFS returns max path from node to leaf -> `left = max(0, dfs(root->left))`, `right = max(0, dfs(root->right))` -> `maxi = max(maxi, left + right + root->data)` -> return `max(left, right) + root->data`.
