# Search in a Binary Search Tree

## Key Idea
Leverage the property of a Binary Search Tree (BST): all nodes in the left subtree are smaller than the root, and all nodes in the right subtree are greater. This allows us to quickly eliminate half of the tree at each step.

## Pattern
Binary Search Tree / Iterative Search

## Approach
- **Loop**: While `root` is not `nullptr` and the current node's data is not equal to the target `val`.
- **Compare**: If the current node's data is greater than `val`, move to the left child (`root = root->left`).
- **Otherwise**: Move to the right child (`root = root->right`).
- **Return**: Once the loop terminates, `root` will either point to the node containing `val` or be `nullptr` if the value is not present in the tree.

## Edge Case
Empty tree. Target value is not present in the tree. Target value is at the root.

## Complexity
Time: O(H) where H is the height of the tree. (O(\log N) for balanced trees, O(N) for skewed trees).
Space: O(1) auxiliary space since it's an iterative approach.

## Revision Note
Iterative: `while(root && root->val != target)` -> `root = (root->val > target) ? root->left : root->right` -> return `root`.
