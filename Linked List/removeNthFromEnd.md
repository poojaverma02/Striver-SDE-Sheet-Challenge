# Remove N-th Node from End of List

## Key Idea
Use two pointers (`slow` and `fast`). Move the `fast` pointer `N` steps ahead. Then move both pointers one step at a time until `fast` reaches the last node. At this point, `slow` will be exactly right before the node to be deleted.

## Pattern
Two Pointers (Fast & Slow)

## Approach
- **Initialize** `fast` and `slow` pointers to the `head`.
- **Move** the `fast` pointer `N` steps forward.
- If `fast == NULL`, it means the node to delete is the head of the list. Return `head->next`.
- **Iterate** moving both `fast` and `slow` one step at a time until `fast->next == NULL`.
- `slow` is now pointing to the node preceding the one to be removed.
- **Delete** the node by updating the link: `slow->next = slow->next->next`.
- **Return** `head`.

## Edge Case
If `N` is exactly the length of the list, `fast` becomes `NULL` after the first loop. This means the head node is the one being removed. We catch this immediately.

## Complexity
Time: O(N) where N is the number of nodes in the linked list (one-pass solution).
Space: O(1) since we only use two pointers.

## Revision Note
Fast pointer `N` steps ahead. If `fast == NULL`, delete head. Else move both until `fast->next == NULL`. `slow` is right behind the target.
