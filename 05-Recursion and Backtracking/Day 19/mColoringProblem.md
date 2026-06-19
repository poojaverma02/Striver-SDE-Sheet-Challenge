# M-Coloring Problem

## Key Idea
Use backtracking to try assigning every possible color from 1 to m to each node, ensuring no two adjacent nodes share the same color.

## Pattern
Recursion / Backtracking

## Approach
- **Build** an adjacency list from the given edges.
- **Initialize** an array `colors` to track assigned colors (0 means uncolored).
- **Recurse** starting from the first node. If all nodes are colored, return true.
- **Try Colors**: For the current node, iterate through colors `1` to `m`.
- **Check Safety**: Check if any adjacent node has the same color. If safe, assign the color, recursively move to the next node.
- **Backtrack**: If it fails to yield a solution, reset the color to 0 and try the next color.

## Edge Case
Graph requiring more than `m` colors or disconnected graphs.

## Complexity
Time: O(M^N)
Space: O(N)

## Revision Note
Build adj list -> recurse node 0 to N-1 -> loop colors 1 to M -> check `isSafe` (no adj same color) -> color -> recurse -> backtrack.
