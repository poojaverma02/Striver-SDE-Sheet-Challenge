# Two Sum In BST

## Key Idea
Similar to the Two Sum problem on a sorted array using two pointers, we can use two iterators on the BST: one traversing normally (inorder, getting smallest elements) and one traversing in reverse (reverse inorder, getting largest elements).

## Pattern
Binary Search Tree / Two Pointers / Iterator

## Approach
- **BSTIterator Class**: Create an iterator that can be initialized in either `normal` (Left-Root-Right) or `reverse` (Right-Root-Left) mode using a boolean flag.
- **Initialization**: Create iterator `l` (normal) pointing to the smallest element, and iterator `r` (reverse) pointing to the largest element.
- **Two Pointers**: Get the initial values `i = l.next()` and `j = r.next()`.
- **Search Loop**: While `i < j`:
  - If `i + j == k`, return `true`.
  - If `i + j < k`, we need a larger sum, so move the left iterator: `i = l.next()`.
  - If `i + j > k`, we need a smaller sum, so move the right iterator: `j = r.next()`.
- Return `false` if no pair is found.

## Edge Case
Empty tree or tree with only one node.

## Complexity
Time: O(N) in the worst case where we might traverse all nodes.
Space: O(H) for the stack space used by the iterators, where H is the height of the tree.

## Revision Note
Two iterators: `next()` (inorder) and `before()` (reverse inorder). Two pointers `i` and `j` -> if `i + j == k` return true, if `< k` move `i`, if `> k` move `j`.
