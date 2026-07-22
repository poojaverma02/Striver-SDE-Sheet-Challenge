# Find the MST Weight (Prim's Algorithm)

## Key Idea
Prim's algorithm finds the Minimum Spanning Tree (MST) of a connected, undirected graph. It starts from an arbitrary node and grows the MST one edge at a time by always picking the minimum weight edge that connects a visited node to an unvisited node. A priority queue (min-heap) is used to efficiently select this minimum edge.

## Pattern
Graph / Minimum Spanning Tree / Greedy / Priority Queue

## Approach
- **Initialization**: Create a `visited` array initialized to `0`. Use a min-heap priority queue storing pairs of `{weight, node}`. Initialize `sum = 0`.
- **Start Traversal**: Push an arbitrary starting node into the priority queue, e.g., `{0, 0}` (weight 0, node 0).
- **Greedy Selection**:
  - While the priority queue is not empty, pop the top element `{wt, node}`.
  - If `node` is already visited, `continue` (this edge forms a cycle).
  - Mark `node` as visited.
  - Add `wt` to the total MST `sum`.
  - Iterate through all neighbors `(adjNode, edgeWt)` of `node`.
  - If a neighbor is not visited, push `{edgeWt, adjNode}` into the priority queue.
- **Return**: Return the accumulated `sum` representing the total weight of the MST.

## Edge Case
Disconnected graphs (Prim's standard implementation only finds the MST for the connected component of the start node). Graph with a single node (sum = 0).

## Complexity
Time: O(E \log E) where $E$ is the number of edges, as each edge is pushed into and popped from the priority queue.
Space: O(V + E) for the priority queue and adjacency list.

## Revision Note
Min-Heap stores `{wt, node}`. Pop top. If visited, skip. Else, mark visited, `sum += wt`. Push all unvisited neighbors with their edge weights.
