# Combination Sum II

## Key Idea
Sort the array to group duplicates, then use recursion to either pick an element once or skip it entirely along with all its duplicates to ensure unique combinations.

## Pattern
Recursion / Backtracking

## Approach
- **Sort** the input array `candidates` to easily skip duplicates.
- **Base Cases**: If `sum == 0`, add the combination. If `sum < 0` or no elements left, return.
- **Take**: Include the current candidate `candidates[i]` and recurse on `i-1` with the reduced sum.
- **Backtrack**: Remove the candidate from the combination.
- **Skip Duplicates**: Find the next non-duplicate element by iterating backwards and recurse on that new index.

## Edge Case
Target cannot be met, or all elements are identical but their sum isn't target.

## Complexity
Time: O(2^N * N)
Space: O(N)

## Revision Note
Sort array -> Take element & move to `i-1` -> backtrack -> Skip duplicates using a loop `while(v[ind] == v[i])` -> recurse.
