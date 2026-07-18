# Topological Sort (DFS)

## Key Idea
In a Depth-First Search (DFS), we can achieve a topological sort by noting when a node finishes processing. Once all descendants (dependencies) of a node are fully processed, the node itself is added to a stack. Popping from the stack at the end yields a valid topological ordering.

## Pattern
Graph Traversal / DFS

## Approach
- **Initialization**: Create a `visited` array (initialized to 0) and an empty stack `st`.
- **DFS Traversal**:
  - Loop through all nodes $0$ to $V-1$ to handle disconnected components.
  - If a node is unvisited, call the recursive `dfs` function.
  - In `dfs`:
    - Mark the current node as visited.
    - Recursively call `dfs` for all unvisited neighbors.
    - **Crucial Step**: After all neighbors are processed, push the current node onto the stack `st`.
- **Generate Result**: 
  - Once all components are traversed, pop elements from the stack one by one and append them to an `ans` vector.
- **Return**: Return the `ans` vector.

## Edge Case
Disconnected graphs. Graph with no edges.

## Complexity
Time: O(V + E) where V is vertices and E is edges.
Space: O(V) for the visited array, recursion stack, and output stack.

## Revision Note
DFS traversal. After visiting all neighbors of `u`, push `u` to stack. The final topo sort is the stack elements popped in reverse order.
