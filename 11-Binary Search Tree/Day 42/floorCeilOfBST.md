# Floor and Ceil in a BST

## Key Idea
The **floor** of a key is the largest value in the BST smaller than or equal to the key. The **ceil** of a key is the smallest value in the BST greater than or equal to the key. We can find both by leveraging the properties of a BST, eliminating half of the search space at each step.

## Pattern
Binary Search Tree / Iterative Search

## Approach
- **Initialize**: Set `floor = -1` and `ceil = -1`.
- **Find Floor**:
  - Start at the `root`.
  - If `current->data == key`, the floor is the key itself. Break.
  - If `current->data < key`, the current node could be the floor. Update `floor = current->data`, and search the right subtree for a closer (larger) value (`current = current->right`).
  - If `current->data > key`, the current node is too large. Search the left subtree (`current = current->left`).
- **Find Ceil**:
  - Reset to `root`.
  - If `current->data == key`, the ceil is the key itself. Break.
  - If `current->data > key`, the current node could be the ceil. Update `ceil = current->data`, and search the left subtree for a closer (smaller) value (`current = current->left`).
  - If `current->data < key`, the current node is too small. Search the right subtree (`current = current->right`).

## Edge Case
Empty tree. Key is smaller than the minimum value (no floor) or larger than the maximum value (no ceil).

## Complexity
Time: O(H) where H is the height of the BST. We traverse down a single path twice.
Space: O(1) auxiliary space (iterative approach).

## Revision Note
**Floor**: If `data <= key`, `floor = data`, go right. Else go left.
**Ceil**: If `data >= key`, `ceil = data`, go left. Else go right.
