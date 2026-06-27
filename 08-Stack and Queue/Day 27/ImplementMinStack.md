# Implement Min Stack

## Key Idea
Store a modified value in the stack whenever a new minimum is encountered to keep track of the previous minimum without using auxiliary space.

## Pattern
Stack / Math

## Approach
- **Push**: If the new value is less than the current `mini`, push a modified value `(2 * value - mini)` onto the stack and update `mini = value`. Otherwise, just push the value.
- **Pop**: If the popped value is less than `mini` (indicating it was a modified value representing the minimum), restore the previous minimum using `mini = 2 * mini - popped_value`.
- **Top**: If the top value is less than `mini`, return `mini` (as the actual top element was the minimum). Otherwise, return the top value.

## Edge Case
Operations on an empty stack.

## Complexity
Time: O(1) for all operations.
Space: O(N)

## Revision Note
Keep `mini` variable -> if `val < mini`, push `2*val - mini`, `mini = val` -> on pop, if `top < mini`, `mini = 2*mini - top`.
