# Subsets II

## Key Idea
Use recursion and backtracking to generate all subsets, while skipping duplicates to ensure only unique subsets are added to the result.

## Pattern
Recursion / Backtracking

## Approach
- **Sort** the input array to group duplicate elements together.
- **Include** the current element in the subset and recurse to the next index.
- **Backtrack** by removing the element.
- **Skip** any duplicate elements by iterating until a different number is found before making the next recursive call.

## Edge Case
Array with all identical elements or an empty array.

## Complexity
Time: O(2^N * N)
Space: O(N)

## Revision Note
Sort array -> include element, recurse -> backtrack -> loop to skip duplicates `nums[j] == nums[ind]` -> recurse on next unique.
