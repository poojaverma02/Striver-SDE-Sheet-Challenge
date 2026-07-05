# Preorder, Inorder, and Postorder in a Single Traversal

## Key Idea
Use a stack holding pairs of `(Node, State)` to generate preorder, inorder, and postorder traversals of a binary tree in a single pass without using recursion.

## Pattern
Tree Traversal / Iterative using Stack

## Approach
- **State Definition**: Let state `1` mean the node is visited in preorder, state `2` for inorder, and state `3` for postorder.
- **Initialize**: Push `{root, 1}` to the stack.
- **Process Stack**: While the stack is not empty, pop the top node:
  - **If State == 1 (Preorder)**: Add node to `pre`, increment its state to `2` and push back to stack. Then, push its left child with state `1`.
  - **If State == 2 (Inorder)**: Add node to `in`, increment its state to `3` and push back to stack. Then, push its right child with state `1`.
  - **If State == 3 (Postorder)**: Add node to `post`. Do not push it back.
- **Return**: A 2D array or tuple containing the three traversals.

## Edge Case
Empty tree.

## Complexity
Time: O(3N) as each node is visited exactly 3 times.
Space: O(4N) for the stack and three traversal vectors.

## Revision Note
Stack of `{node, state}` -> state 1: push `pre`, increment state, push `left` -> state 2: push `in`, increment state, push `right` -> state 3: push `post`.
