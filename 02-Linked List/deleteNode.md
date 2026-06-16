# Delete Node in a Linked List

## Key Idea
Since we are only given a pointer to the node to be deleted (and not the `head`), we cannot traverse from the previous node. Instead, we copy the value of the next node into the current node, and then bypass the next node by linking the current node's `next` to `next->next`.

## Pattern
Pointer Manipulation (Value Override)

## Approach
- **Copy** the value: `node->val = node->next->val`.
- **Skip** the next node: `node->next = node->next->next`.
- (Optional but good practice) Delete the skipped node from memory.

## Edge Case
The node to be deleted is guaranteed not to be a tail node according to typical problem constraints, so `node->next` will never be `NULL`.

## Complexity
Time: O(1) constant time operation.
Space: O(1) constant auxiliary space.

## Revision Note
No head given! Copy `next->val` to `curr->val`. Point `curr->next` to `curr->next->next`.
