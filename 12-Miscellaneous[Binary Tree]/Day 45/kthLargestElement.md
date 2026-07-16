# K-th Largest Element in an Array

## Key Idea
Finding the $K$-th largest element is equivalent to finding the element at index $K-1$ if the array was sorted in descending order. The Quickselect algorithm (based on Quicksort partitioning) solves this efficiently on average without fully sorting the array.

## Pattern
Divide and Conquer / Quickselect

## Approach
- **Quickselect**:
  - Maintain a search space defined by `left` and `right`.
  - Choose a random pivot index using `randomIndex(left, right)`.
  - Partition the array around the pivot such that elements strictly greater than the pivot are placed to its left.
  - Get the new index of the pivot after partitioning.
  - If `pivotIndex == k - 1`, we found the $K$-th largest element. Return it.
  - If `pivotIndex > k - 1`, the target is in the left portion. Update `right = pivotIndex - 1`.
  - If `pivotIndex < k - 1`, the target is in the right portion. Update `left = pivotIndex + 1`.

## Edge Case
$K$ is out of bounds ($K > N$). Array with identical elements. 

## Complexity
Time: O(N) on average. O(N^2) in the worst case (though using a random pivot makes this extremely unlikely).
Space: O(1) auxiliary space as it modifies the array in-place.

## Revision Note
Quickselect. Random pivot. Partition: elements $>$ pivot go to the left side (since we want Kth largest). If `pivotIndex == k-1`, return. If `> k-1`, search left half. If `< k-1`, search right half.
