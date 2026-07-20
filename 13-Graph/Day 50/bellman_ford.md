# Bellman Ford Algorithm

## Key Idea
The Bellman-Ford algorithm finds the shortest path from a source vertex to all other vertices in a weighted graph. Unlike Dijkstra's, it can handle negative weight edges. It works by "relaxing" all edges $V-1$ times. If we can relax an edge one more time (the $V$-th time), it means there is a negative weight cycle.

## Pattern
Graph / Shortest Path / Dynamic Programming (Edge Relaxation)

## Approach
- **Initialization**: Create a `dist` array of size $V$ initialized to infinity (`1e9`). Set `dist[S] = 0` for the source.
- **Edge Relaxation ($V-1$ times)**: 
  - Loop $V-1$ times.
  - In each iteration, loop over all edges $(u, v, wt)$.
  - If `dist[u]` is not infinity and `dist[u] + wt < dist[v]`, update `dist[v] = dist[u] + wt`.
- **Negative Cycle Detection (1 time)**:
  - Loop over all edges one more time.
  - If any edge can still be relaxed (`dist[u] + wt < dist[v]`), it indicates a negative weight cycle. Return `{-1}`.
- **Return**: Return the `dist` array.

## Edge Case
Graph with negative weight cycles. Disconnected components (unreachable nodes will have distance `1e9`).

## Complexity
Time: O(V \times E) because we iterate through all $E$ edges $V$ times.
Space: O(V) for the distance array.

## Revision Note
Relax all edges $V-1$ times: `if (dist[u] + wt < dist[v]) dist[v] = dist[u] + wt`. The $V$-th relaxation checks for negative cycles.
