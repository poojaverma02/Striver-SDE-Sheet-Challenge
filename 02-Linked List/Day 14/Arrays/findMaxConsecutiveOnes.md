# Maximum Consecutive Ones

## Key Idea
Traverse the array, maintaining a count of consecutive 1s and resetting it to zero when a 0 is encountered. Keep track of the maximum count.

## Pattern
Array Traversal / Two Variables

## Approach
- **Initialize** `cnt` to track current consecutive 1s and `maxi` to store the maximum count.
- **Traverse** the array; if the element is 1, increment `cnt` and update `maxi`.
- **Reset** `cnt` to 0 when encountering a 0.

## Edge Case
Array with all 0s or all 1s.

## Complexity
Time: O(N)
Space: O(1)

## Revision Note
Maintain a running count of 1s, reset on 0. Update the max count at each step.
