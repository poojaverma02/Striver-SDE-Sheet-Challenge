# Clone Graph

## Key Idea
To perform a deep copy of an undirected graph, we need to traverse it (using DFS or BFS) and create copies of each node. A hash map is essential to keep track of already visited/cloned nodes to prevent infinite loops (due to cycles) and ensure we don't duplicate the same node multiple times.

## Pattern
Graph Traversal / DFS / Hash Map

## Approach
- **Hash Map**: Use an `unordered_map<Node*, Node*> visited` to map original nodes to their cloned counterparts.
- **DFS Traversal**: 
  - If the input node is `nullptr`, return `nullptr`.
  - In the `dfs` function, first check if the `node` is already in the `visited` map. If so, return the stored clone.
  - If not visited, create a new `Node` (the clone) with the same value as the original node.
  - Immediately store this mapping: `visited[node] = clone`.
  - Iterate through all neighbors of the original node. For each neighbor, recursively call `dfs` and push the returned cloned neighbor into the `clone->neighbors` list.
- **Return**: Return the cloned node.

## Edge Case
Empty graph (`node == nullptr`). Graph with a single node (no neighbors). Graph with self-loops or multiple cycles.

## Complexity
Time: O(V + E) where V is the number of vertices and E is the number of edges, as every node and every edge is processed exactly once.
Space: O(V) for the hash map storing the clones, and O(V) for the recursion stack in the worst-case (a linear graph).

## Revision Note
Hash map `visited`: original $\rightarrow$ clone. DFS: if visited, return clone. Else create clone, put in map, iterate neighbors $\rightarrow$ `clone.neighbors.push_back(dfs(neighbor))`. Return clone.
