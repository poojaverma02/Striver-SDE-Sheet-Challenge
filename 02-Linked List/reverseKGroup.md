# Reverse Nodes in k-Group

## Key Idea
Traverse the linked list and identify groups of `k` nodes. Reverse each identified group, keeping track of the links between the reversed groups. If fewer than `k` nodes remain, leave them as they are.

## Pattern
Pointer Manipulation + Group Reversal

## Approach
- **Initialize** a `temp` pointer at the `head` and a `prevLast` pointer to `NULL`.
- **Loop** through the list while `temp != NULL`.
- Find the `kThNode` of the current group using a helper function.
- If `kThNode == NULL` (meaning fewer than `k` nodes remain), connect the previous reversed group to `temp` and break the loop.
- Save the `nextNode = kThNode->next`.
- Disconnect the group by setting `kThNode->next = NULL`.
- Reverse the group starting at `temp` (using standard linked list reversal).
- Connect the newly reversed group:
  - If it's the first group (`temp == head`), update the main `head` to `kThNode`.
  - Else, connect `prevLast->next = kThNode`.
- Update `prevLast = temp` (since `temp` was the head of the group before reversal, it is now the tail).
- Move `temp = nextNode` to process the next group.

## Edge Case
- The length of the list is not a multiple of `k`. The code correctly handles this by breaking out and leaving the remainder untouched.
- `k = 1`. Each node forms its own group, resulting in no actual structural changes, though handled naturally.

## Complexity
Time: O(2N) ~ O(N). The `getKthNode` traverses nodes once, and the `reverseLinkedList` traverses them a second time.
Space: O(1) modifying pointers in place.

## Revision Note
Find the K-th node. If NULL, just link remainder and break. Cut the list at K-th node. Reverse the K-length segment. Link `prevLast` to the new head (`kThNode`). Update `prevLast` to `temp`.
