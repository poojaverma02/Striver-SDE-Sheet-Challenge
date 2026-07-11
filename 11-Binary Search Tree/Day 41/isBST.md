# Check if a Tree is a BST or Not

## Key Idea
A binary tree is a valid Binary Search Tree (BST) if every node's value lies within a specific valid range `(min, max)`. As we traverse down the tree, we tighten these bounds for the left and right subtrees.

## Pattern
Binary Search Tree / Range Validation

## Approach
- **Recursive Validation Function**: Create a helper function `validate(node, min, max)` that takes a node and the allowed bounds.
- **Initial Bounds**: Start with the widest possible bounds: `LLONG_MIN` and `LLONG_MAX`. (Using `long long` prevents false negatives if the tree contains `INT_MIN` or `INT_MAX`).
- **Base Case**: If the node is `nullptr`, it's valid, return `true`.
- **Check Bounds**: If the node's data is outside the valid range (`<= min` or `>= max`), return `false`.
- **Recursion**: Recursively validate the left subtree by updating the `max` bound to the current node's data, and the right subtree by updating the `min` bound to the current node's data. Both must be true.

## Edge Case
Empty tree. Trees containing `INT_MIN` or `INT_MAX` as node values.

## Complexity
Time: O(N) since every node is visited exactly once.
Space: O(H) for the recursion stack where H is the height of the tree.

## Revision Note
`validate(node, min, max)` -> if `node == null` return true -> if `data <= min || data >= max` return false -> return `validate(left, min, data) && validate(right, data, max)`.
