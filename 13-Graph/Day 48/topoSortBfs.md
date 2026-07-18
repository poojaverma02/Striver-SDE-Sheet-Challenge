# Topological Sort (Kahn's Algorithm - BFS)

## Key Idea
Topological sorting of a Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge $u \rightarrow v$, vertex $u$ comes before $v$ in the ordering. Kahn's Algorithm uses BFS, leveraging in-degrees to iteratively strip away nodes that have no prerequisites (in-degree of 0).

## Pattern
Graph Traversal / BFS / Kahn's Algorithm

## Approach
- **In-degree Array**: Calculate the in-degree for all nodes by iterating over the adjacency list.
- **Initialize Queue**: Create a queue and push all vertices with an in-degree of 0.
- **BFS Traversal**:
  - While the queue is not empty, pop the front node `u`.
  - Add `u` to the result list `ans`.
  - Iterate through all neighbors `v` of `u`.
  - Decrement the in-degree of `v` (`inDegree[v]--`).
  - If the in-degree of `v` becomes 0, push `v` into the queue.
- **Return**: Return the `ans` array.

## Edge Case
Graph is empty. Graph is not a DAG (though the problem guarantees a DAG for standard topological sort).

## Complexity
Time: O(V + E) where V is the number of vertices and E is the number of edges.
Space: O(V) for the queue, in-degree array, and result list.

## Revision Note
Find in-degrees $\rightarrow$ Queue nodes with 0 in-degree $\rightarrow$ pop, add to `ans`, decrement neighbors' in-degree, push if 0. Returns a valid topo sort.
