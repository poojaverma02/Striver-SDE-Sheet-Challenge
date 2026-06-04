# Kadane's Algorithm

## Key Idea
Maintain a running sum of elements and a maximum sum. If the running sum ever drops below zero, reset it to zero since negative sums decrease the future total.

## Pattern
Array manipulation (Running Sum)

## Approach
- **Iterate** through the array, adding elements to `sum`.
- **Update** `maxi` if `sum > maxi`.
- **Reset** `sum` to `0` if `sum < 0`.

## Edge Case
All negative elements. The algorithm works if we update `maxi` before resetting `sum`.

## Complexity
Time: O(N)
Space: O(1)

## Revision Note
Keep adding -> Update max -> Reset to 0 if negative.
