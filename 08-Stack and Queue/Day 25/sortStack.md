# Sort a Stack

## Key Idea
Use recursion to pop all elements from the stack until it's empty, and then insert each element back into its correct sorted position using a helper recursive function.

## Pattern
Recursion / Stack

## Approach
- **`sortStack`**:
  - Base case: If the stack is empty, return.
  - Remove the top element, recursively call `sortStack` on the rest of the stack.
  - Insert the removed element back into the sorted stack using `insertSorted`.
- **`insertSorted`**:
  - Base case: If the stack is empty or its top is `<= element`, push the element.
  - Otherwise, remove the top element, recursively call `insertSorted` for the element, and then push the removed top element back.

## Edge Case
Stack is already sorted, or contains duplicate elements.

## Complexity
Time: O(N²)
Space: O(N) (call stack size)

## Revision Note
`sortStack(st)` pops top, recurses, then `insertSorted(st, top)`. `insertSorted(st, ele)` pops larger elements until empty or `top <= ele`, pushes `ele`, then pushes back larger elements.
