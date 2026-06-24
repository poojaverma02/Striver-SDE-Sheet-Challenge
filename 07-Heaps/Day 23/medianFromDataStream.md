# Find Median from Data Stream

## Key Idea
Maintain two heaps: a Max-Heap for the left (smaller) half of the data, and a Min-Heap for the right (larger) half, ensuring sizes differ by at most 1 to quickly retrieve the median.

## Pattern
Two Heaps (Max Heap & Min Heap)

## Approach
- **Add Number**: First, push the new number into the `maxH` (left half).
- **Order Guarantee**: If `maxH.top() > minH.top()`, the element belongs in the right half, so move `maxH.top()` to `minH`.
- **Balance Sizes**: Ensure `maxH` has either the same number of elements as `minH` or exactly one more. If imbalanced, move the top element from the larger heap to the smaller one.
- **Find Median**: If `maxH.size() > minH.size()`, return `maxH.top()`. Otherwise, return the average of both tops.

## Edge Case
Finding the median when only 1 or 2 elements have been inserted.

## Complexity
Time: O(log N) for addNum, O(1) for findMedian.
Space: O(N)

## Revision Note
Max-heap (left) & Min-heap (right) -> push left -> if left.top > right.top, move to right -> balance sizes (`diff <= 1`) -> median is top or average of tops.
