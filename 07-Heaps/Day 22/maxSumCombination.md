# Maximum Sum Combination

## Key Idea
Sort both arrays in descending order and use a Max Heap to systematically generate and track the largest sum combinations without computing all possible pairs.

## Pattern
Max Heap / Priority Queue / Two Pointers

## Approach
- **Sort** both arrays `nums1` and `nums2` in descending order.
- **Initialize** a max heap with the largest possible sum `(nums1[0] + nums2[0])` and its indices `(0, 0)`. Use a `set` to track visited index pairs.
- **Extract** the top of the heap $K$ times to get the $K$ largest sums.
- **Push Neighbors**: For each extracted pair `(i, j)`, push its neighbors `(i+1, j)` and `(i, j+1)` into the heap if they haven't been visited yet.

## Edge Case
$K$ is 1 or $K$ equals the total number of possible combinations.

## Complexity
Time: O(K log K)
Space: O(K)

## Revision Note
Sort descending -> max heap stores `{sum, {i, j}}` -> pop top -> push `{i+1, j}` and `{i, j+1}` if not visited -> repeat $K$ times.
