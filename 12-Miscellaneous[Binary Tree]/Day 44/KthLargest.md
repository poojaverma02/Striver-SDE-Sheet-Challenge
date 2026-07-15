# Kth Largest Element in a Stream

## Key Idea
To efficiently find the $K$-th largest element in a continuous stream of data, we can maintain a Min-Heap of size exactly $K$. The smallest element in this heap (the root) will always be the $K$-th largest element seen so far.

## Pattern
Heap / Priority Queue (Min-Heap)

## Approach
- **Initialization**: 
  - Store the integer $K$.
  - Initialize a min-heap (`priority_queue<int, vector<int>, greater<int>>`).
  - Iterate through the initial array:
    - If the heap size is less than $K$, simply push the element.
    - If the heap size is exactly $K$ and the current element is greater than the top (smallest) element of the heap, pop the top and push the new element.
- **Add Element**: 
  - When a new element arrives, apply the same logic: push it if the heap is not full ($< K$). If it's larger than the heap's minimum, pop the minimum and push the new element.
  - The top of the heap is the $K$-th largest element.

## Edge Case
Initial array is empty. Stream length is exactly $K$.

## Complexity
Time: O(N \log K) for initialization. O(\log K) for each `add` operation.
Space: O(K) to store the elements in the min-heap.

## Revision Note
Min-Heap of size $K$. If `size < K`, push. Else if `val > pq.top()`, pop and push `val`. Return `pq.top()`.
