# 3 Sum

## Key Idea
Sort the array and fix one number, then use the two-pointer approach to find the other two numbers that sum up to zero, skipping duplicates to ensure unique triplets.

## Pattern
Sorting / Two Pointers

## Approach
- **Sort** the input array.
- **Iterate** through the array, fixing an element `nums[i]`. Skip duplicate values for `nums[i]`.
- **Use Two Pointers** (`j` and `k`) for the remaining array to find pairs summing to `-nums[i]`.
- **Skip Duplicates** for `j` and `k` to ensure unique triplets.

## Edge Case
Array with less than 3 elements or all zeroes.

## Complexity
Time: O(NlogN) + O(N²)
Space: O(1)

## Revision Note
Sort array -> loop `i` -> two pointers `j` and `k` -> skip duplicates for `i`, `j`, and `k` to avoid repeating triplets.
