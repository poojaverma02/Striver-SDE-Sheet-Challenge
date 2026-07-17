# Detect Cycle in a Directed Graph

## Key Idea
In a directed graph, a cycle exists if we encounter a back-edge during traversal. This means we reach a node that is currently in the active recursion stack (i.e., it is part of the current path being explored). We use two arrays: one to track visited nodes overall, and another to track nodes in the current path.

## Pattern
Graph Traversal / DFS / Path Tracking

## Approach
- **Initialization**: Create a `visited` array and a `pathVisited` array, both initialized to `false`. Iterate through all nodes to handle disconnected components.
- **DFS Traversal**:
  - Mark the `node` as visited in both `visited` and `pathVisited` arrays.
  - Iterate through all neighbors of `node`.
  - **Cycle Condition**: If a neighbor is already `pathVisited`, a cycle is detected! Return `true`.
  - If a neighbor is not `visited`, recursively call `dfs`. If it returns `true`, propagate it.
  - **Backtrack**: After exploring all neighbors, remove the `node` from the current path: `pathVisited[node] = false`.
- **Return**: If no cycle is found across all components, return `false`.

## Edge Case
Disconnected graphs. Self-loops (a node points to itself).

## Complexity
Time: O(V + E) where V is the number of vertices and E is the number of edges.
Space: O(V) for the `visited` array, `pathVisited` array, and the recursion stack.

## Revision Note
Keep track of two arrays: `visited` and `pathVisited`. In DFS, mark both true. If neighbor is `pathVisited`, cycle found. Before returning from DFS, backtrack: `pathVisited[node] = false`.
