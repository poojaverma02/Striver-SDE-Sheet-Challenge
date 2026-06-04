# Find the Duplicate Number

## Key Idea
Treat the array values as node pointers to create a linked list. Use Floyd's Tortoise and Hare algorithm to detect the cycle and find its starting node (the duplicate).

## Pattern
Cycle Detection (Tortoise and Hare)

## Approach
- **Initialize** `slow` and `fast` pointers to `nums[0]`.
- **Move** `slow` by 1 step (`nums[slow]`) and `fast` by 2 steps (`nums[nums[fast]]`) until they meet.
- **Reset** `slow` back to `nums[0]`.
- **Move** both pointers by 1 step until they meet again. 
- **Return** the meeting point.

## Edge Case
The array values must be in the range `[1, n]`. Safely guaranteed by the problem constraints.

## Complexity
Time: O(N)
Space: O(1)

## Revision Note
Detect cycle (slow 1, fast 2) -> Reset slow to start -> Move both by 1 -> Meeting point is duplicate.
