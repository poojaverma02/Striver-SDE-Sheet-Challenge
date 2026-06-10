# Merge Two Sorted Lists

## Key Idea
Use a dummy node to simplify edge cases. Use two pointers to traverse both sorted linked lists simultaneously, attaching the smaller node to the merged list at each step.

## Pattern
Two Pointers + Dummy Node

## Approach
- **Initialize** a `dummyNode` with a placeholder value (e.g., `-1`) and a `temp` pointer pointing to it.
- **Traverse** both lists `list1` and `list2` while neither is `NULL`.
- Compare the values of the current nodes in both lists.
- If `list1->val <= list2->val`, attach `list1` to `temp->next` and advance `list1`.
- Otherwise, attach `list2` to `temp->next` and advance `list2`.
- Advance `temp`.
- Once one list is exhausted, attach the remainder of the other list directly to `temp->next`.
- **Return** `dummyNode->next` (the head of the newly merged list).

## Edge Case
One or both lists are initially empty. The while loop handles this gracefully, and the remaining list check will attach the non-empty list (if any) or `NULL`.

## Complexity
Time: O(N1 + N2) where N1 and N2 are the lengths of the two linked lists.
Space: O(1) since we only use a few pointers and reuse the existing nodes.

## Revision Note
Dummy node approach! `temp = dummyNode`. Compare nodes, attach the smaller one, move pointers. Don't forget to attach the remaining nodes after the loop!
