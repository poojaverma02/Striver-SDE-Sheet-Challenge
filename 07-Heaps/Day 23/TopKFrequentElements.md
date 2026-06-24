# Top K Frequent Elements

## Key Idea
Count the frequencies of each element, then use a Min-Heap of size $K$ to keep track of the $K$ most frequent elements. The least frequent among the top $K$ will always be at the top of the Min-Heap.

## Pattern
Min Heap / Hash Map

## Approach
- **Count Frequencies**: Use a hash map (`unordered_map`) to count occurrences of each number.
- **Maintain Top K**: Iterate through the hash map and push `{frequency, number}` pairs into a Min-Heap.
- **Evict**: If the heap size exceeds $K$, pop the top element (which has the smallest frequency currently in the heap).
- **Extract**: Once all elements are processed, the heap contains the $K$ most frequent elements. Extract them into the result vector.

## Edge Case
$K$ is equal to the number of unique elements.

## Complexity
Time: O(N log K)
Space: O(N + K)

## Revision Note
Map for frequencies -> Min-heap of size K (`greater<>`) -> push `{freq, num}` -> if `size > k`, `pop()` -> remaining elements are top K.
