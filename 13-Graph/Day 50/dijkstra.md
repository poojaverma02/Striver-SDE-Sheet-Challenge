# Dijkstra's Algorithm

## Key Idea
Dijkstra's algorithm finds the shortest paths from a source node to all other nodes in a graph with non-negative edge weights. It uses a greedy approach, always exploring the closest unvisited node using a priority queue or a set.

## Pattern
Graph / Shortest Path / Greedy

## Approach
- **Initialization**: Create an adjacency list. Create a `dist` array initialized to infinity (`1e9`). Set `dist[S] = 0`.
- **Set Data Structure**: Use a `set<pair<int, int>>` to store `{distance, node}`. This keeps the nodes sorted by their current shortest distance. Insert `{0, S}` into the set.
- **Traversal**:
  - While the set is not empty, extract the minimum distance node (the first element).
  - Iterate through all its neighbors `(adjNode, edgeWt)`.
  - **Relaxation**: If `current_dist + edgeWt < dist[adjNode]`, we found a shorter path.
  - If `dist[adjNode]` is not infinity, erase the old pair from the set (to update its position).
  - Update `dist[adjNode] = current_dist + edgeWt`.
  - Insert the new `{dist[adjNode], adjNode}` into the set.
- **Return**: Return the `dist` array.

## Edge Case
Disconnected graphs (unreachable nodes remain `1e9`). *Note: Dijkstra fails with negative edge weights.*

## Complexity
Time: O((V + E) \log V) because each edge is processed and inserting/erasing from the set takes $O(\log V)$.
Space: O(V + E) for the adjacency list and $O(V)$ for the distance array and set.

## Revision Note
Use a `set` (or `priority_queue`) to pick the smallest distance node. If `dis + edgeWt < dist[adjNode]`, erase the old distance (if it exists) from the set, update `dist[adjNode]`, and insert the new distance into the set.
