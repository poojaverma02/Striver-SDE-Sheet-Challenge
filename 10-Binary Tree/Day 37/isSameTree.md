# Check if Two Trees are Identical or Not

## Key Idea
Two binary trees are considered identical if they are structurally identical and the nodes have the same value. We can verify this by simultaneously traversing both trees and comparing corresponding nodes.

## Pattern
Tree Traversal / DFS

## Approach
- **Base Case**: If either node `p` or `q` is `NULL`, return true if both are `NULL`, otherwise false (`return p == q`).
- **Data Comparison**: If the values of the current nodes (`p->data` and `q->data`) do not match, return false.
- **Recursive Check**: Recursively call the function for both the left subtrees and the right subtrees. The trees are identical only if both recursive calls return true.

## Edge Case
One or both trees are empty. Structurally identical trees with different node values.

## Complexity
Time: O(N) where N is the number of nodes in the smaller tree.
Space: O(H) for the recursion stack where H is the height of the tree.

## Revision Note
Base case: `if (!p || !q) return p == q;` -> value check: `if (p->data != q->data) return false;` -> recursive check: `return isSameTree(left) && isSameTree(right);`.
