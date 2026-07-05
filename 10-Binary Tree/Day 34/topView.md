# Top View of Binary Tree

## Key Idea
Use Level Order Traversal (BFS) and a map to keep track of the vertical distance of each node. Since we want the top view, only insert the node's value into the map if the vertical line has not been visited yet.

## Pattern
Tree Traversal / BFS / Hash Map

## Approach
- **Initialize**: Use a `map<int, int>` to store the first encountered node value for each vertical distance. Use a `queue<pair<TreeNode*, int>>` for BFS, starting with `{root, 0}`.
- **BFS Traversal**: Pop the front of the queue. If the current vertical distance is not present in the map, insert the node's data. (This ensures only the topmost node is captured).
- **Children**: Push the left child with vertical distance `line - 1` and the right child with `line + 1`.
- **Extract Result**: Iterate over the map (automatically sorted by keys) and push the values into the result array.

## Edge Case
Empty tree. Nodes that overlap on the same vertical line at the same depth (BFS guarantees left-to-right order).

## Complexity
Time: O(N \log N) due to map insertions.
Space: O(N) for the map and queue.

## Revision Note
Queue `{node, line}` -> if `map.find(line) == map.end()`, insert `node->data` -> left: `line-1`, right: `line+1` -> extract values from map.
