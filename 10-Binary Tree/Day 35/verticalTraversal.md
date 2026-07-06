# Vertical Order Traversal of Binary Tree

## Key Idea
Traverse the tree using BFS while keeping track of the vertical (`x`) and horizontal (`y`) distances. Group nodes by `x`, then `y`, and resolve overlaps by sorting node values in ascending order.

## Pattern
Tree Traversal / BFS / Hash Map + Priority Queue

## Approach
- **Map Structure**: Use a nested map: `map<int, map<int, priority_queue<int, vector<int>, greater<int>>>>` to map `x` -> `y` -> `min-heap of values`.
- **BFS Traversal**: Use a queue storing `{node, {x, y}}`. Start with `{root, {0, 0}}`.
- **Process Node**: Pop a node, insert its data into the `nodesMap[x][y]`.
- **Children**: Push the left child with `{x - 1, y + 1}`. Push the right child with `{x + 1, y + 1}`.
- **Extract Result**: Iterate through the `nodesMap` (automatically sorted by `x`, then `y`). Empty the priority queues to get overlapping values in sorted order and push them to the final result column by column.

## Edge Case
Nodes overlapping at the same position `(x, y)` which need to be sorted. Empty tree.

## Complexity
Time: O(N \cdot \log N) for map insertions and heap operations.
Space: O(N) for the map, priority queue, and BFS queue.

## Revision Note
BFS with `{node, {x, y}}` -> `map[x][y].push(node->data)` (min-heap) -> left: `{x-1, y+1}`, right: `{x+1, y+1}` -> iterate map and pop heaps.
