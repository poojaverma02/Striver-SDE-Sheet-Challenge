# Kth Smallest and Largest Element in BST

## Key Idea
An **inorder traversal** (Left-Root-Right) of a BST visits nodes in strictly ascending order, which is perfect for finding the Kth *smallest* element. Conversely, a **reverse inorder traversal** (Right-Root-Left) visits nodes in strictly descending order, perfect for finding the Kth *largest* element.

## Pattern
Binary Search Tree / Inorder Traversal

## Approach
- **Kth Smallest**: 
  - Perform an inorder traversal (Left, Root, Right).
  - Maintain a counter `k`.
  - Every time a node is processed, decrement `k`.
  - When `k == 0`, record the current node's value as the result and stop traversing.
- **Kth Largest**:
  - Perform a reverse inorder traversal (Right, Root, Left).
  - Similarly, decrement `k` when processing a node.
  - When `k == 0`, record the current node's value as the result and stop.
- **Combined Method**: Run both searches sequentially and return the pair of results.

## Edge Case
`k` is greater than the number of nodes in the BST (though typically `k` is valid). Empty tree.

## Complexity
Time: O(H + K) in the worst case, as we might traverse down to the leaf and then process K elements.
Space: O(H) for the recursion stack where H is the height of the tree.

## Revision Note
Smallest: Inorder (Left, Root, Right).
Largest: Reverse Inorder (Right, Root, Left).
In both, decrement `k` at the root step; if `k == 0`, save result and return.
