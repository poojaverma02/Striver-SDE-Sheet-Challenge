# Maximum Width of Binary Tree

## Key Idea
Use Level Order Traversal (BFS) and assign indices to nodes as if they were in a complete binary tree. The width of any level is the difference between the indices of the last and first nodes plus one.

## Pattern
Tree Traversal / BFS / Indexing

## Approach
- **Indexing Rule**: If a node has index `i`, its left child has index `2*i + 1` and right child has index `2*i + 2`.
- **BFS Traversal**: Use a queue storing `{node, index}`. Start with `{root, 0}`.
- **Normalize Indices**: To prevent integer overflow, normalize indices at each level by subtracting the minimum index (`mmin`) of that level from all node indices before calculating children indices.
- **Calculate Width**: For each level, track the `first` and `last` normalized index. Update `ans = max(ans, last - first + 1)`.

## Edge Case
Empty tree. Deeply skewed trees causing potential integer overflow if indices are not normalized.

## Complexity
Time: O(N) as each node is processed once.
Space: O(N) for the BFS queue.

## Revision Note
BFS storing `{node, index}` -> normalize index: `cur_id = index - mmin` -> left child: `2*cur_id + 1`, right child: `2*cur_id + 2` -> `width = last - first + 1`.
