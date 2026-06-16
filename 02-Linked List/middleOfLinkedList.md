# Find Middle of Linked List

## Key Idea
Use the Tortoise and Hare (Slow and Fast Pointers) approach. By the time the fast pointer (moving 2 steps at a time) reaches the end, the slow pointer (moving 1 step at a time) will be exactly at the middle.

## Pattern
Fast & Slow Pointers

## Approach
- **Initialize** `slow` and `fast` pointers at the `head` of the linked list.
- **Iterate** while `fast` and `fast->next` are not `NULL`.
- **Move** `slow` by 1 step (`slow = slow->next`).
- **Move** `fast` by 2 steps (`fast = fast->next->next`).
- When the loop terminates, `slow` will point to the middle node.
- **Return** `slow`.

## Edge Case
- Empty list: The condition `fast != NULL` fails immediately, safely skipping the loop.
- List with even number of nodes: `fast->next` will become `NULL`, and `slow` will point to the second middle node, which satisfies the problem requirements.

## Complexity
Time: O(N/2) ~ O(N) as the fast pointer traverses the list at double speed.
Space: O(1) since only two pointers are used.

## Revision Note
Tortoise and Hare! `slow` moves 1 step, `fast` moves 2 steps. Loop condition is `fast != NULL && fast->next != NULL`.
