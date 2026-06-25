# Implement Stack using Queue

## Key Idea
Use a single queue and simulate stack (LIFO) behavior by pushing the new element and then rotating all previously existing elements to the back of the queue.

## Pattern
Queue Rotation

## Approach
- **Push**: Get the current size `s` of the queue. Push the new element `x` to the back.
- **Rotate**: Loop `s` times, popping the front element and pushing it to the back. This moves `x` to the front of the queue, making it act like the top of a stack.
- **Pop / Top**: The front of the queue now holds the most recently pushed element. Simply use the queue's native `pop()` and `front()` operations.

## Edge Case
Popping or calling top on an empty structure.

## Complexity
Time: O(N) for push operation. O(1) for pop and top.
Space: O(N) using only a single queue.

## Revision Note
Push to queue -> loop `size` times -> push `front()` to back and `pop()` -> front is always the top of stack.
