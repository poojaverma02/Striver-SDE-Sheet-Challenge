# Detect Cycle in an Undirected Graph (DFS)

## Key Idea
Similar to the BFS approach, a cycle in an undirected graph can be detected using DFS. If during the recursive traversal we encounter a node that is already visited and is not the parent from which we arrived, a cycle exists.

## Pattern
Graph Traversal / DFS

## Approach
- **Initialization**: Create a `visited` array initialized to `false`. Iterate through all nodes to handle disconnected components.
- **DFS Traversal**:
  - The recursive function `dfs` takes `node`, `visited` array, and `parent` node.
  - Mark `node` as visited.
  - Iterate through all neighbors of `node`.
  - If a neighbor is not visited, recursively call `dfs(neighbor, ..., node)`. If this call returns `true`, propagate the `true` upwards.
  - **Cycle Condition**: If the neighbor is already visited AND `neighbor != parent`, return `true`.
- **Return**: If DFS finishes for all components without returning `true`, return `false`.

## Edge Case
Disconnected graphs. Graph with only 1 or 2 nodes and no cycles.

## Complexity
Time: O(V + E) as every vertex and edge is visited at most once.
Space: O(V) for the visited array and the recursion stack.

## Revision Note
DFS state needs `(node, parent)`. If neighbor is visited and `neighbor != parent`, cycle exists! Handle disconnected components using a loop over all vertices.
