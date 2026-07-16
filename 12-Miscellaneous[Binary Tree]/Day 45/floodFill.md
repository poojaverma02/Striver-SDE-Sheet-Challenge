# Flood Fill

## Key Idea
The Flood Fill algorithm replaces a connected region of a specific color with a new color. This is a classic graph traversal problem that can be solved efficiently using Depth First Search (DFS) or Breadth First Search (BFS).

## Pattern
Graph Traversal / DFS (or BFS) / Matrix

## Approach
- **Initialization**: Store the initial color of the starting pixel `iniColor = image[sr][sc]`. Create a copy of the image to store the updated colors (`ans`).
- **DFS Traversal**: Create a recursive `dfs` function.
  - Color the current pixel: `ans[row][col] = newColor`.
  - Iterate through the 4 directional neighbors (up, right, down, left) using `delRow` and `delCol` arrays.
  - For each neighbor, check if it's within valid boundaries (`isValid`).
  - Check if the neighbor has the original color (`image[nrow][ncol] == iniColor`) and hasn't been updated to the new color yet (`ans[nrow][ncol] != newColor`).
  - If valid, recursively call `dfs` on the neighbor.
- **Return**: Return the updated `ans` matrix.

## Edge Case
The starting pixel is already the `newColor`. The image contains only 1 pixel.

## Complexity
Time: O(N \times M) where $N$ and $M$ are the dimensions of the image. In the worst case, we visit every pixel once.
Space: O(N \times M) for the recursion stack and the copied answer matrix.

## Revision Note
Save `iniColor`. If `iniColor == newColor`, return. Use `dfs(r, c)`: color current cell, check 4 neighbors using `delRow={-1,0,1,0}` and `delCol={0,1,0,-1}`. If neighbor is valid, is `iniColor`, and isn't `newColor`, recursively call `dfs`.
