# Floyd Warshall Algorithm

## Key Idea
The Floyd-Warshall algorithm is a dynamic programming approach to find the shortest paths between all pairs of vertices in a directed, weighted graph. It works by considering each vertex one by one as an intermediate node to see if a path going through it is shorter than the known direct path.

## Pattern
Graph / All-Pairs Shortest Path / Dynamic Programming

## Approach
- **Initialization**: The algorithm operates directly on an adjacency matrix where `matrix[i][j]` represents the distance from node $i$ to node $j$. Missing edges are usually represented by infinity or $-1$.
- **Triple Loop**: Iterate with $k$ from $0$ to $n-1$ (treating node $k$ as an intermediate node).
  - Iterate with $i$ from $0$ to $n-1$ (source node).
    - Iterate with $j$ from $0$ to $n-1$ (destination node).
- **Relaxation**: For each $(i, j)$ pair, check if going through $k$ provides a valid, shorter path.
  - If `matrix[i][k]` or `matrix[k][j]` is $-1$ (no path), skip.
  - If `matrix[i][j]` is $-1$ (no direct path yet), update it to `matrix[i][k] + matrix[k][j]`.
  - Otherwise, update `matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j])`.
- **Return**: The matrix itself gets updated with all-pairs shortest distances.

## Edge Case
Disconnected nodes (distance remains $-1$). Self-loops. Can detect negative cycles if `matrix[i][i] < 0` after completion.

## Complexity
Time: O(N^3) due to the three nested loops.
Space: O(N^2) (or $O(1)$ auxiliary space if modifying the input matrix in place).

## Revision Note
3 nested loops: `k`, `i`, `j`. Try relaxing path $i \rightarrow j$ via $k$. Check for valid paths (`!= -1`). Formula: `dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])`.
