# Majority Element II (n/3 times)

## Key Idea
Use Boyer-Moore Voting Algorithm to find at most two elements that could appear more than `N/3` times.

## Pattern
Array Manipulation (Voting Algorithm)

## Approach
- **Initialize** `cnt1 = 0, cnt2 = 0` and `el1 = INT_MIN, el2 = INT_MIN`.
- **Iterate** over each element in the array to find potential majority candidates.
- **Update** counts or candidates appropriately.
- **Reset** counts to `0` and **Iterate** again to verify if `el1` and `el2` actually appear more than `N/3` times.
- **Return** the verified elements.

## Edge Case
Ensure `el1` and `el2` are distinct candidates when pushing to the result.

## Complexity
Time: O(2N)
Space: O(1)

## Revision Note
Keep two counts and two elements. Validate the counts in a second pass.