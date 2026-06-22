# Aggressive Cows

## Key Idea
Sort the stall positions, then use binary search to find the maximum possible minimum distance between cows by greedily placing them.

## Pattern
Binary Search on Answer / Greedy

## Approach
- **Sort** the array of stall positions.
- **Set** the binary search range `low = 1` and `high = max_element - min_element`.
- **Check Function**: Iterate through the stalls to place a cow whenever the distance from the last placed cow is `>= mid`.
- **Adjust Boundaries**: If `cows` can be placed with `mid` distance, save the answer and search right (`low = mid + 1`). Otherwise, search left (`high = mid - 1`).

## Edge Case
Only 2 cows to place, placing them at the extremities.

## Complexity
Time: O(NlogN) + O(N * log(max-min))
Space: O(1)

## Revision Note
Sort array -> BS on distance `[1, max - min]` -> `canWePlace` returns true if `count >= cows` -> if true, `low = mid + 1`.
