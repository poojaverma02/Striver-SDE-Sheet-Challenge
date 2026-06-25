# Implement Stack using Arrays

## Key Idea
Use a dynamically allocated array and an integer `topIndex` to track the position of the most recently added element, fulfilling the Last-In-First-Out (LIFO) property.

## Pattern
Array / Stack

## Approach
- **Initialize** an array with a specified capacity and set `topIndex = -1`.
- **Push**: Check for stack overflow (`topIndex >= capacity - 1`). If safe, pre-increment `topIndex` and assign the new value.
- **Pop**: Check for stack underflow (`topIndex == -1`). If safe, return the value at `topIndex` and then decrement `topIndex`.
- **Top / isEmpty**: Return the value at `topIndex`, and check if `topIndex == -1`.

## Edge Case
Pushing to a full stack or popping/peeking from an empty stack.

## Complexity
Time: O(1) for all operations.
Space: O(N) where N is the maximum capacity of the stack.

## Revision Note
Initialize `top = -1` -> Push: `arr[++top] = x` -> Pop: `return arr[top--]`.
