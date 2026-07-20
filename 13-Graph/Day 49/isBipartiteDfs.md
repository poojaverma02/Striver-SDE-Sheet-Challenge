# Check if Graph is Bipartite (DFS)

## Key Idea
Similar to BFS, we can use DFS to check if a graph is bipartite by attempting to color nodes with two alternate colors. As we recursively traverse deep into the graph, we color each unvisited neighbor with the opposite color.

## Pattern
Graph Traversal / DFS / Graph Coloring

## Approach
- **Initialization**: Create a `color` array initialized to `-1`. Build the adjacency list from the edges.
- **Traversal of Components**: Iterate through all nodes. If a node is uncolored, start a DFS from it, assigning it an initial color of $0$.
- **DFS Traversal**:
  - The recursive `dfs(node, col, color, adj)` assigns `color[node] = col`.
  - Traverse all adjacent nodes.
  - If a neighbor is uncolored (`-1`), recursively call `dfs` with the opposite color (`!col`). If the recursive call returns `false`, propagate it upwards by returning `false`.
  - If a neighbor is already colored and has the *same* color as `col`, a conflict is found. Return `false`.
- **Return**: If the DFS completes for all components without conflicts, return `true`.

## Edge Case
Disconnected graphs. Graphs with odd-length cycles (will return `false`).

## Complexity
Time: O(V + E) where V is vertices and E is edges, as every node and edge is processed at most once.
Space: O(V) for the `color` array, adjacency list, and recursion stack.

## Revision Note
Use DFS. Pass `node` and expected `col`. Set `color[node] = col`. For neighbors: if uncolored, call `dfs(neighbor, !col)`. If colored and `color[neighbor] == col`, return `false`.
