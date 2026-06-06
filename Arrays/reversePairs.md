# Reverse Pairs

## Key Idea
Use the Merge Sort algorithm, counting reverse pairs during the merge step where `nums[i] > 2 * nums[j]` and `i < j`.

## Pattern
Divide and Conquer (Merge Sort Modified)

## Approach
- **Divide** the array into two halves recursively until base cases are reached.
- **Count** the valid reverse pairs where `left` half element is strictly greater than twice the `right` half element before merging.
- **Merge** the two sorted halves into a single sorted array.
- **Return** the total count of such pairs.

## Edge Case
Using `long long` when multiplying `nums[right]` by 2 prevents integer overflow.

## Complexity
Time: O(2N * logN)
Space: O(N)

## Revision Note
Count pairs *before* merging. Use `long long` for `2 * nums[right]` to avoid overflow!
