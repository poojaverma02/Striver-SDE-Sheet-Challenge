# Level Order Traversal

## Key Idea
Traverse the tree level by level, from left to right, by using a queue. This is a standard Breadth-First Search (BFS) approach.

## Pattern
Tree Traversal / BFS

## Approach
- **Initialize**: Use a `queue<TreeNode*>` and push the `root`. Create a `vector<vector<int>>` for the result.
- **Loop**: While the queue is not empty, get the current `size` of the queue, which represents the number of nodes at the current level.
- **Process Level**: Loop `size` times. In each iteration, pop a node, add its value to a temporary level array, and push its non-null left and right children into the queue.
- **Store Level**: After the inner loop, append the temporary level array to the final result.

## Edge Case
Empty tree.

## Complexity
Time: O(N) where N is the number of nodes.
Space: O(N) for the queue (at most holds the maximum width of the tree, which can be N/2).

## Revision Note
BFS using queue -> loop while queue not empty -> get `size = q.size()` -> loop `size` times: pop node, push children -> add level vector to answer.
