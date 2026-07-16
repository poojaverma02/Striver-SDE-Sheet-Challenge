# Graph Traversal Techniques (BFS and DFS)

## Key Idea
Graph traversal involves visiting all vertices in a graph systematically. 
- **BFS (Breadth-First Search)** explores the graph level by level, starting from a given node and visiting all its immediate neighbors before moving to the next level. It uses a Queue.
- **DFS (Depth-First Search)** explores as far as possible along each branch before backtracking. It uses recursion (or a Stack).
Both require a `visited` array to avoid processing nodes multiple times and getting stuck in cycles.

## Pattern
Graph Traversal / BFS / DFS

## Approach
- **Common Initialization**:
  - Convert the given `edges` list into an adjacency list `adj` for efficient neighbor lookup.
  - Create a `vis` (visited) array of size $V$ initialized to $0$.
  - Create an `ans` vector to store the traversal order.
  - Since the graph might be disconnected, loop through all nodes $0$ to $V-1$. If a node is not visited, call the traversal function.
- **BFS**:
  - Mark the start node as visited and push it into a queue.
  - While the queue is not empty, pop the front node, add it to `ans`.
  - Iterate through its neighbors. If a neighbor is not visited, mark it visited and push it to the queue.
- **DFS**:
  - Mark the current node as visited and add it to `ans`.
  - Recursively call the DFS function for all its unvisited neighbors.

## Edge Case
Disconnected graphs. Graph with no edges.

## Complexity
Time: O(V + E) for both BFS and DFS, as each vertex and edge is visited once.
Space: O(V) for the visited array, adjacency list, and Queue (BFS) / Recursion Stack (DFS).

## Revision Note
**BFS**: Queue, mark visited when pushing to queue.
**DFS**: Recursion, mark visited when entering recursive function.
For both, check all nodes in a loop to handle disconnected components.
