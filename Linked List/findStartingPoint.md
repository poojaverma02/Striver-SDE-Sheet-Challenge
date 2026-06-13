# Find the Starting Point of Loop in LinkedList

## Key Idea
Use Floyd's Cycle-Finding Algorithm (Tortoise and Hare) to detect the loop, then reset one pointer to the head and move both one step at a time to find the start of the loop.

## Pattern
Two Pointers (Slow & Fast Pointers)

## Approach
- **Initialize** `slow` and `fast` pointers at the head.
- **Traverse** moving `slow` by 1 step and `fast` by 2 steps until they meet.
- **Reset** `slow` to the head when they meet.
- **Move** both `slow` and `fast` by 1 step at a time until they meet again; this is the starting point.

## Edge Case
No loop exists (return NULL if fast reaches the end).

## Complexity
Time: O(N)
Space: O(1)

## Revision Note
`slow = head, fast = head` -> `slow = slow->next, fast = fast->next->next` -> detect -> reset `slow = head` -> move 1 step -> meet at start.
