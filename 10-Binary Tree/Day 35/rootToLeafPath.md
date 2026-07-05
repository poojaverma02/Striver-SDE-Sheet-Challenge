# Print Root to Leaf Paths

## Key Idea
Use Depth First Search (DFS) to traverse the tree while maintaining a running list of the path taken. When a leaf node is reached, record the path and backtrack to explore other branches.

## Pattern
Tree Traversal / DFS / Backtracking

## Approach
- **Initialize**: Use a `vector<vector<int>>` to store all paths and a `vector<int>` to store the current path.
- **DFS Function**: Pass the current node, current path, and results array.
- **Base Case**: If node is `NULL`, return.
- **Append**: Push the current node's data to the path.
- **Leaf Check**: If both left and right children are `NULL`, push the current path into the results array.
- **Traverse**: Call DFS recursively on the left and right children.
- **Backtrack**: Pop the current node's data from the path before returning to the parent call.

## Edge Case
Empty tree, or a tree with only a root node.

## Complexity
Time: O(N) to visit all nodes.
Space: O(N) for the recursion stack in the worst case (skewed tree) and path storage.

## Revision Note
DFS tracking `path` -> `path.push_back` -> if leaf, add `path` to `allPaths` -> DFS left & right -> `path.pop_back` (backtrack).
