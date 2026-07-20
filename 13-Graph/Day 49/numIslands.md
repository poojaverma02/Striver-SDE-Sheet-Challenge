# Number of Islands

## Key Idea
In a grid of '1's (land) and '0's (water), an island is formed by connected '1's. We can find the total number of islands by scanning the grid and initiating a traversal (BFS or DFS) every time we find an unvisited '1'. The traversal will visit and mark the entire connected island.

## Pattern
Graph Traversal / Matrix BFS (or DFS) / Connected Components

## Approach
- **Initialization**: Get grid dimensions $N$ and $M$. Create a 2D `visited` array initialized to `false`. Initialize `count = 0`.
- **Grid Scan**: Use nested loops to iterate through every cell $(i, j)$ in the grid.
- **New Island Found**: If a cell is '1' and not visited:
  - Increment `count`.
  - Start a BFS from this cell to mark all connected lands.
- **BFS Traversal**:
  - Use a queue storing coordinates `{row, col}`.
  - Mark the start cell as visited and push it into the queue.
  - While queue is not empty, pop the current cell.
  - Iterate through all 8 neighbors (using `delRow` and `delCol` loops from -1 to 1).
  - If the neighbor is within bounds, is a '1', and is unvisited: mark it visited and push to the queue.
- **Return**: Return `count`.

## Edge Case
Grid with all '0's (returns 0). Grid with all '1's (returns 1). 1x1 grid. Note: The implementation checks 8 neighbors (including diagonals), adapt to 4 neighbors if the problem specifies horizontally/vertically only.

## Complexity
Time: O(N \times M) as each cell is processed and pushed to the queue at most once.
Space: O(N \times M) for the visited array and queue size in the worst case.

## Revision Note
Scan grid. If `!vis[i][j]` and `grid[i][j]=='1'`, `count++` and `BFS(i, j)`. BFS marks all connected '1's as visited.
