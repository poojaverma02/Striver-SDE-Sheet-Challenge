# Detect Cycle in an Undirected Graph (BFS)

## Key Idea
In an undirected graph, a cycle exists if during a BFS traversal we encounter a node that has already been visited, and that node is *not* the parent of the current node. This implies there is an alternative path to reach the visited node.

## Pattern
Graph Traversal / BFS

## Approach
- **Initialization**: Create a `visited` array initialized to `false`. Since the graph may be disconnected, loop through all nodes from $0$ to $V-1$ and start a BFS if the node is unvisited.
- **BFS Traversal**:
  - Use a queue storing pairs: `{current_node, parent_node}`.
  - Push the starting node with parent `-1` and mark it visited.
  - While the queue is not empty, pop the front element.
  - Iterate through all neighbors of `current_node`.
  - If a neighbor is not visited, mark it visited and push `{neighbor, current_node}` to the queue.
  - **Cycle Condition**: If a neighbor is already visited AND it is not equal to the `parent_node`, a cycle is detected. Return `true`.
- **Return**: If the queue empties and no cycle is found for any component, return `false`.

## Edge Case
Disconnected graphs. Graph with no edges (returns `false`).

## Complexity
Time: O(V + E) where V is the number of vertices and E is the number of edges.
Space: O(V) for the visited array and the BFS queue.

## Revision Note
BFS queue stores `{node, parent}`. If neighbor is visited and `neighbor != parent`, cycle exists! Handle disconnected components using a loop over all vertices.
