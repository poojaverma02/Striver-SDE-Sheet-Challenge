# Zig-Zag or Spiral Traversal

## Key Idea
Traverse the tree level by level using BFS, but alternate the insertion order (left-to-right or right-to-left) of nodes into the level's result array based on a direction flag.

## Pattern
Tree Traversal / BFS

## Approach
- **Initialize**: Use a queue for BFS starting with the `root`. Maintain a boolean flag `leftToRight` set to `true`.
- **Level Processing**: For each level, determine its size. Create a temporary vector `row` of that size.
- **Fill Row**: Pop nodes from the queue. Calculate their index in `row` based on the `leftToRight` flag: if `true`, index is `i`; if `false`, index is `size - 1 - i`. Add the node's value to the row and push its children to the queue.
- **Toggle Direction**: After finishing a level, flip the `leftToRight` flag and push the completed `row` to the result.

## Edge Case
Empty tree.

## Complexity
Time: O(N) as every node is visited exactly once.
Space: O(N) for the BFS queue.

## Revision Note
BFS queue -> `vector<int> row(size)` -> index is `i` if `leftToRight` else `size - 1 - i` -> push children -> `leftToRight = !leftToRight`.
