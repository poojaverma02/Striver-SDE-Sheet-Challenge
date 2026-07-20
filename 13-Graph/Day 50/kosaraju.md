# Kosaraju's Algorithm (Strongly Connected Components)

## Key Idea
Kosaraju's algorithm finds all Strongly Connected Components (SCCs) in a directed graph. It uses two DFS passes: one to find the topological ordering (finishing time) of nodes, and another on the reversed graph to discover the isolated SCCs.

## Pattern
Graph / DFS / Strongly Connected Components

## Approach
- **Step 1 (Order by Finishing Time)**: Perform DFS on the original graph. When a DFS finishes for a node (all its descendants are visited), push it onto a `stack`.
- **Step 2 (Reverse Graph)**: Create a transposed (reversed) graph by flipping the direction of all edges. Reset the `visited` array.
- **Step 3 (Count SCCs)**: 
  - While the `stack` is not empty, pop the top node.
  - If it is unvisited, increment the SCC `count` and perform a DFS on the *reversed* graph (`helperDFS`) starting from this node. This DFS will visit all nodes in the current SCC.
- **Return**: Return the `count` of SCCs.

## Edge Case
Graph with no edges (each node is its own SCC). Graph which is entirely one SCC (returns 1).

## Complexity
Time: O(V + E) for the two DFS passes and reversing the graph.
Space: O(V + E) to store the reversed graph and O(V) for the stack and visited arrays.

## Revision Note
1. DFS $\rightarrow$ store in Stack on finish. 2. Reverse all edges. 3. Pop from Stack $\rightarrow$ if unvisited, `count++` and run DFS on reversed graph.
