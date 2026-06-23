# Implement Max Heap

## Key Idea
Use an array to represent the binary tree structure of the heap, maintaining the max-heap property (parent is always larger than its children) through `heapifyUp` and `heapifyDown` operations.

## Pattern
Heap / Priority Queue

## Approach
- **Insert**: Push the new element to the end of the array and `heapifyUp` by comparing and swapping with its parent `(ind - 1) / 2`.
- **Extract Max**: Replace the root with the last element, reduce the size, and `heapifyDown` by swapping with the largest child.
- **Change Key**: Update the value at the given index. If the new value is larger, `heapifyUp`; if smaller, `heapifyDown`.
- **Get Max**: Return the element at index `0`.

## Edge Case
Extracting or changing keys in an empty heap.

## Complexity
Time: O(logN) for insert/extract/change, O(1) for getMax.
Space: O(N)

## Revision Note
Array-based tree -> `parent = (i-1)/2`, `left = 2i+1`, `right = 2i+2` -> `heapifyUp` on insert -> `heapifyDown` on extract.
