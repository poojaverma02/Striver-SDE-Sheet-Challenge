# Inorder Successor and Predecessor in BST

## Key Idea
In a BST, the inorder predecessor is the largest node smaller than the given key, and the inorder successor is the smallest node larger than the given key. We can find both simultaneously by traversing the tree based on the target key.

## Pattern
Binary Search Tree / Tree Traversal

## Approach
- **Initialize**: Set `predecessor` and `successor` to `NULL`. Set `curr = root`.
- **Search Loop**: While `curr` is not `NULL`:
  - If `key > curr->data`: The current node is smaller than the key, so it's a potential `predecessor`. Record it (`predecessor = curr`) and move right to find a larger one closer to the key.
  - If `key < curr->data`: The current node is larger than the key, so it's a potential `successor`. Record it (`successor = curr`) and move left to find a smaller one closer to the key.
  - If `key == curr->data`: The exact node is found. 
    - **Predecessor**: The maximum value in its left subtree (rightmost node in the left subtree).
    - **Successor**: The minimum value in its right subtree (leftmost node in the right subtree).
    - Break the loop.
- **Return**: Extract the values from the `predecessor` and `successor` nodes (return -1 if `NULL`).

## Edge Case
The key does not exist in the tree. The key is the minimum or maximum value (meaning no predecessor or successor exists, respectively).

## Complexity
Time: O(H) where H is the height of the tree.
Space: O(1) auxiliary space as it uses an iterative approach.

## Revision Note
While `curr`: if `key > data`, `pred = curr`, `curr = right`. If `key < data`, `succ = curr`, `curr = left`. If `key == data`: `pred` is rightmost in left subtree, `succ` is leftmost in right subtree.
