# Implement Queue using Stack

## Key Idea
Use two stacks (`input` and `output`) to simulate a queue. Elements are pushed onto `input`, and when a pop or peek is requested, elements are lazily transferred to `output` to reverse their order, ensuring FIFO.

## Pattern
Two Stacks

## Approach
- **Push**: Always push the new element onto the `input` stack. This takes O(1) time.
- **Pop / Peek**: If the `output` stack is empty, pop all elements from `input` and push them onto `output`. This reverses the LIFO order of the stack into the FIFO order of a queue.
- The top of the `output` stack is now the oldest element (front of the queue). Pop or peek from `output`.

## Edge Case
Popping or peeking when both stacks are empty.

## Complexity
Time: O(1) Amortized for pop/peek. Push is O(1).
Space: O(N) where N is the total number of elements.

## Revision Note
Push to `input` -> Pop/Peek: if `output` empty, transfer all from `input` to `output` -> return `output.top()`.
