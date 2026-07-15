# Find Median in a Data Stream

## Key Idea
To find the median dynamically as data flows in, we can divide the data into two halves: the lower half stored in a **Max-Heap**, and the upper half stored in a **Min-Heap**. The median is either the top of the Max-Heap or the average of the tops of both heaps.

## Pattern
Heap / Two Heaps (Min-Heap and Max-Heap)

## Approach
- **Initialize**: Use `left` (Max-Heap) for the smaller half of numbers, and `right` (Min-Heap) for the larger half.
- **Add Element**: 
  - Step 1: Always add a new number to `left` first if it's empty or the number is $\le$ the top of `left`. Otherwise, add it to `right`.
  - Step 2: Balance the heaps. We maintain a rule that `left` can have at most 1 more element than `right`. If `left.size() > right.size() + 1`, move `left.top()` to `right`. If `right.size() > left.size()`, move `right.top()` to `left`.
- **Compute Median**: 
  - If sizes are equal, the median is `(left.top() + right.top()) / 2.0`.
  - If sizes are not equal, since `left` is allowed to be larger, the median is `left.top()`.

## Edge Case
Empty stream. Stream with identical elements.

## Complexity
Time: O(N \log N) to process all elements, where each insertion takes O(\log N) time.
Space: O(N) to store all the elements in the two priority queues.

## Revision Note
Max-Heap (`left`), Min-Heap (`right`). Insert into `left` if $\le$ `left.top()`, else `right`. Balance so `left` has at most 1 more than `right`. Median is avg of tops or just `left.top()`.
