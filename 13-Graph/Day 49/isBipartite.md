# Check if Graph is Bipartite (BFS)

## Key Idea
A graph is bipartite if its nodes can be colored using exactly two colors such that no two adjacent nodes have the same color. We can use BFS to traverse the graph and attempt to color it level by level with alternating colors.

## Pattern
Graph Traversal / BFS / Graph Coloring

## Approach
- **Initialization**: Create a `color` array of size $V$ initialized to `-1` (uncolored). Create an adjacency list from the given edges.
- **Traversal of Components**: Iterate through all nodes. If a node is uncolored (`color[i] == -1`), start a BFS from it.
- **BFS Traversal**:
  - Color the starting node with $0$ and push it into a queue.
  - While the queue is not empty, pop a node.
  - Traverse all its neighbors:
    - If a neighbor is uncolored (`-1`), color it with the opposite color of the current node (`!color[node]`) and push it into the queue.
    - If a neighbor is already colored and has the *same* color as the current node, the graph is not bipartite. Return `false`.
- **Return**: If all components are successfully colored, return `true`.

## Edge Case
Disconnected graphs. Graph with no edges (is bipartite). Graph with odd-length cycles (not bipartite).

## Complexity
Time: O(V + E) as each vertex and edge is visited at most once.
Space: O(V) for the queue, color array, and adjacency list.

## Revision Note
Use BFS and a `color` array initialized to `-1`. Push uncolored node, color it $0$. For neighbors: if uncolored, color with `!color[curr]` and push; if colored with same color, return `false`.
