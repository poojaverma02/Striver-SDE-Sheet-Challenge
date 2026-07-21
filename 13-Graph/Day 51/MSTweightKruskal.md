# Find the MST Weight (Kruskal's Algorithm)

## Key Idea
Kruskal's algorithm finds the Minimum Spanning Tree (MST) of a connected, undirected graph. It follows a greedy approach by sorting all edges by weight and adding them to the MST one by one, provided they don't form a cycle. A Disjoint Set (Union-Find) is used to efficiently detect cycles.

## Pattern
Graph / Minimum Spanning Tree / Greedy / Disjoint Set (Union-Find)

## Approach
- **Disjoint Set Structure**: Implement a `DisjointSet` class with path compression (`findUPar`) and union by rank or size (`unionBySize`).
- **Edge Extraction**: Traverse the given adjacency list to extract all edges into a list of format `{weight, {u, v}}`.
- **Sorting**: Sort the edge list in ascending order of weights.
- **Kruskal's Traversal**:
  - Initialize `sum = 0`.
  - Iterate through the sorted edges.
  - For each edge `(wt, u, v)`, check if $u$ and $v$ belong to the same set using `findUPar`.
  - If they belong to different sets (no cycle will be formed), add `wt` to `sum` and unite them using `unionBySize`.
- **Return**: Return the accumulated `sum` representing the total weight of the MST.

## Edge Case
Disconnected graphs (the result will be a minimum spanning forest).

## Complexity
Time: O(E \log E) to sort the edges. The Disjoint Set operations take $O(E \alpha(V))$ which is nearly $O(E)$.
Space: O(V + E) for the edge list and the Disjoint Set parent/size arrays.

## Revision Note
1. Extract all edges: `{wt, {u, v}}`. 2. Sort edges by `wt`. 3. Iterate edges: if `find(u) != find(v)`, add `wt` to `sum`, `union(u, v)`. Needs Disjoint Set with path compression.
