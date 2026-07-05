# Bottom View of Binary Tree

## Key Idea
Use Level Order Traversal (BFS) and a map to keep track of the vertical distance of each node. Since we want the bottom view, continuously update the map with the latest node value for each vertical line.

## Pattern
Tree Traversal / BFS / Hash Map

## Approach
- **Initialize**: Use a `map<int, int>` to store the node values keyed by their vertical distance. Use a `queue<pair<TreeNode*, int>>` for BFS traversal, initialized with `{root, 0}`.
- **BFS Traversal**: Pop the front of the queue. Update the map with the current node's value for its vertical line (this will overwrite any previous value, keeping the lowest node).
- **Children**: If a left child exists, push it to the queue with vertical distance `line - 1`. If a right child exists, push it with `line + 1`.
- **Extract Result**: After BFS, iterate over the map (which is automatically sorted by the vertical distance keys) and push the values into the result array.

## Edge Case
Empty tree.

## Complexity
Time: O(N \log N) due to map insertions.
Space: O(N) for the map and queue.

## Revision Note
Queue `{node, line}` -> `map[line] = node->data` (always update) -> left: `line-1`, right: `line+1` -> extract values from map.
