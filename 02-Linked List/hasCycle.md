# Detect a Cycle in a Linked List

## Key Idea
Use the Tortoise and Hare approach (Fast and Slow pointers). If there is a cycle, the fast pointer will eventually "lap" and meet the slow pointer. If there isn't, the fast pointer will reach the end (`NULL`).

## Pattern
Fast & Slow Pointers (Tortoise and Hare)

## Approach
- **Initialize** `slow` and `fast` pointers to the `head` of the list.
- **Loop** while `fast != NULL` and `fast->next != NULL`.
- Move `slow` one step: `slow = slow->next`.
- Move `fast` two steps: `fast = fast->next->next`.
- If `slow == fast`, a cycle exists. **Return** `true`.
- If the loop terminates, the list has an end. **Return** `false`.

## Edge Case
- Empty list or single node without cycle. The `while` condition catches `fast == NULL` or `fast->next == NULL` and properly returns `false`.

## Complexity
Time: O(N) where N is the number of nodes. In the worst case, the fast pointer loops through the cycle.
Space: O(1) as only two pointers are used.

## Revision Note
Tortoise & Hare! Slow moves 1 step, Fast moves 2 steps. If they ever equal each other, there's a loop.
