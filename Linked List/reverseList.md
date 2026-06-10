# Reverse a Linked List

## Key Idea
Iteratively reverse the `next` pointers of each node. Store the next node temporarily before changing the current node's pointer so that you don't lose the rest of the list.

## Pattern
Pointer Manipulation

## Approach
- **Initialize** `temp` to `head` (the current node) and `prev` to `NULL`.
- **Traverse** the list while `temp != NULL`.
- **Store** the next node: `front = temp->next`.
- **Reverse** the link: `temp->next = prev`.
- **Move** `prev` forward: `prev = temp`.
- **Move** `temp` forward: `temp = front`.
- After the loop, `prev` will be pointing to the new head of the reversed list.
- **Return** `prev`.

## Edge Case
- Empty list (`head == NULL`): The loop doesn't run, and it correctly returns `NULL`.
- Single node list: The loop runs once, `temp->next` becomes `NULL`, and it returns the single node as the new head.

## Complexity
Time: O(N) as we traverse the list exactly once.
Space: O(1) since we only use three pointers (`temp`, `prev`, `front`).

## Revision Note
Keep three pointers: `prev` (NULL), `temp` (head), `front` (temp->next). Update links: `temp->next = prev`, then shift all three forward. Return `prev`.
