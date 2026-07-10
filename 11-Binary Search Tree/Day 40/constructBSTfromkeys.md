# Convert Sorted Array to Binary Search Tree

## Key Idea
To construct a height-balanced Binary Search Tree from a sorted array, the middle element of the array should always be the root. The left half of the array forms the left subtree, and the right half forms the right subtree.

## Pattern
Binary Search Tree / Divide and Conquer

## Approach
- **Recursive Helper**: Create a recursive function that takes the array, a `beg` index, and an `end` index.
- **Base Case**: If `beg > end`, return `nullptr` as it represents an invalid range.
- **Find Mid**: Calculate the middle index `mid = (beg + end) / 2`.
- **Create Node**: Create a new `TreeNode` with the value `nums[mid]`.
- **Recursion**: 
  - Recursively build the left subtree using the range `[beg, mid - 1]`.
  - Recursively build the right subtree using the range `[mid + 1, end]`.
- **Return Root**: Return the newly created node.

## Edge Case
Empty array. Array with a single element. Arrays with even number of elements (either middle element can be the root).

## Complexity
Time: O(N) as each element of the array is visited exactly once to create a node.
Space: O(\log N) for the recursion stack (since the tree is balanced, the height is $\log N$).

## Revision Note
Root is `nums[mid]` -> `left = dfs(beg, mid-1)` -> `right = dfs(mid+1, end)`.
