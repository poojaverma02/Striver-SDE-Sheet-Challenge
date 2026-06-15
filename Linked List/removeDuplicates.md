# Remove Duplicates from Sorted Array

## Key Idea
Use two pointers to keep track of the last unique element placed and the current element being processed.

## Pattern
Two Pointers (Slow & Fast)

## Approach
- **Initialize** a slow pointer `i` at the first element to track unique elements.
- **Iterate** a fast pointer `j` from the second element to the end.
- **Update** `nums[++i] = nums[j]` if `nums[i] != nums[j]` to store the unique element.

## Edge Case
Array with all identical elements or already unique elements.

## Complexity
Time: O(N)
Space: O(1)

## Revision Note
Use a slow pointer for the sorted unique portion and a fast pointer to explore. `nums[++i] = nums[j]` when different.
