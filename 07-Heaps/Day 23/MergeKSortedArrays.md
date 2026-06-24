# Merge K Sorted Arrays

## Key Idea
Use a Min-Heap to efficiently find the minimum element among the current pointers of all $K$ sorted arrays, maintaining a sorted order as elements are extracted and their successors are inserted.

## Pattern
Min Heap / K-way Merge

## Approach
- **Initialize** a Min-Heap that stores a tuple: `{value, {array_index, element_index}}`.
- **Push** the first element of each of the $K$ arrays into the Min-Heap.
- **Process**: While the heap is not empty, extract the top element (the smallest overall) and append it to the result array.
- **Advance**: If the extracted element has a next element in its original array, push that next element into the heap.

## Edge Case
Some or all of the $K$ arrays might be empty.

## Complexity
Time: O(K² log K), assuming K arrays of size K. In general, O(N log K) where N is the total number of elements.
Space: O(K)

## Revision Note
Min-heap of `{val, {row, col}}` -> push 1st element of every row -> loop: pop top, push to result -> push `{row, col+1}` element if it exists.
