# Distinct Numbers in Each Subarray

## Key Idea
To find the number of distinct elements in every sliding window of size $K$, we can use a hash map to keep track of the frequency of elements in the current window. As the window slides, we add the new element and remove the outgoing element, updating the frequencies and the map size accordingly.

## Pattern
Sliding Window / Hash Map

## Approach
- **Initialize Hash Map**: Create an `unordered_map<int, int> freq`.
- **First Window**: Iterate through the first $K$ elements and increment their frequency in the map. The number of distinct elements in the first window is `freq.size()`. Add this to the result array.
- **Slide Window**: For each subsequent element from index $K$ to $N-1$:
  - Identify the `outgoing` element at index $i - K$. Decrement its frequency in the map. If its frequency becomes $0$, remove it completely from the map using `freq.erase(outgoing)`.
  - Identify the `incoming` element at index $i$. Increment its frequency in the map.
  - The number of distinct elements in the current window is `freq.size()`. Add this to the result array.

## Edge Case
$K = 1$. The array length $N$ is equal to $K$.

## Complexity
Time: O(N) as each element is added and removed from the hash map at most once, and map operations take $O(1)$ on average.
Space: O(K) for the hash map storing at most $K$ distinct elements.

## Revision Note
Use a frequency map. First $K$ elements $\rightarrow$ add to map, result is `map.size()`. From $i = K$ to $N$: decrement `nums[i-K]`, erase if $0$; increment `nums[i]`; result is `map.size()`.
