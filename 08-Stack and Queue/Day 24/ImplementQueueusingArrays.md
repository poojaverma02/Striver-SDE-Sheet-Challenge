# Implement Queue using Arrays

## Key Idea
Use a dynamically allocated fixed-size array and track the `start` and `end` indices, applying modulo arithmetic to achieve a circular queue behavior, thus avoiding memory waste.

## Pattern
Array / Circular Queue

## Approach
- **Initialize** an array of `maxSize`, with `start` and `end` initialized to `-1` and `currSize` to `0`.
- **Push**: Check for overflow. If empty, set `start` and `end` to 0. Otherwise, increment `end` using `(end + 1) % maxSize` and assign the value.
- **Pop**: Check for underflow. Store the value at `start`. If it was the last element, reset indices to `-1`. Otherwise, increment `start` using `(start + 1) % maxSize`.
- **Peek / isEmpty**: Return the element at `start`, and return true if `currSize == 0`.

## Edge Case
Pushing into a full queue or popping/peeking from an empty queue.

## Complexity
Time: O(1) for all operations.
Space: O(N) where N is the maximum size of the queue.

## Revision Note
Use `currSize`, `start`, `end` -> Push: `end = (end + 1) % maxSize` -> Pop: `start = (start + 1) % maxSize`.
