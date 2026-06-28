# Rotting Oranges

## Key Idea
Use Multi-source Breadth-First Search (BFS) to simulate the rotting process simultaneously from all initially rotten oranges level by level.

## Pattern
Graph / BFS

## Approach
- **Initialize**: Traverse the grid to count the total number of oranges (`total`) and push the coordinates of all initially rotten oranges (`2`) into a queue.
- **BFS Traversal**: Process the queue level by level. For each rotten orange, check its 4 neighbors.
- **Rot Neighbors**: If a neighbor is a fresh orange (`1`), make it rotten (`2`), push it to the queue, and increment the rotted count.
- **Track Time**: Increment the `time` counter after processing each entire level (if new oranges were rotted).
- **Check Complete**: If the final count of rotted oranges equals the initial total, return `time`; otherwise, return `-1`.

## Edge Case
Grid with no fresh oranges (time is 0), or fresh oranges that are unreachable.

## Complexity
Time: O(N * M)
Space: O(N * M)

## Revision Note
Multi-source BFS -> queue pushes all `2`s -> process level by level (`time++`) -> rot adjacent `1`s -> check if `rotted == total`.
