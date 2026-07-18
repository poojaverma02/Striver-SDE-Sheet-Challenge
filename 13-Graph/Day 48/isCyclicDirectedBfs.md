# Detect Cycle in a Directed Graph (BFS - Kahn's Algorithm)

## Key Idea
Topological sorting is only possible for Directed Acyclic Graphs (DAG). Using Kahn's Algorithm (BFS) for topological sorting, if the graph contains a cycle, we will not be able to process all $V$ vertices because the nodes forming the cycle will never have their in-degrees reduced to zero. Thus, if the topological sort produces fewer than $V$ nodes, a cycle exists.

## Pattern
Graph Traversal / BFS / Kahn's Algorithm

## Approach
- **In-degree Array**: Calculate the in-degree (number of incoming edges) for all nodes.
- **Initialize Queue**: Push all nodes with an in-degree of 0 into a queue.
- **BFS Processing**:
  - Pop a node from the queue and add it to a `topo` list.
  - For each neighbor of the popped node, decrement its in-degree.
  - If a neighbor's in-degree becomes 0, push it into the queue.
- **Cycle Check**: 
  - After the queue is empty, check the size of the `topo` list.
  - If `topo.size() < V`, it means some nodes could not be processed due to a cycle. Return `true`.
  - Else, return `false`.

## Edge Case
Graph with no edges (returns `false`). Disconnected components with a cycle in one of them.

## Complexity
Time: O(V + E) as we calculate in-degrees and process each node and its outgoing edges exactly once.
Space: O(V) for the in-degree array, queue, and topo list.

## Revision Note
Kahn's algorithm: `inDegree` array $\rightarrow$ queue nodes with `inDegree == 0` $\rightarrow$ pop, decrement neighbors' `inDegree`, push if $0$. If `topo.size() < V` $\rightarrow$ cycle exists.
