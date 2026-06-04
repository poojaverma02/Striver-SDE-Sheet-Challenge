# Merge Overlapping Subintervals

## Key Idea
Sort the intervals based on the start time, then iteratively merge overlapping ones by comparing the end of the last merged interval with the start of the current one.

## Pattern
Sorting + Intervals

## Approach
- **Sort** the intervals by their start times.
- **Iterate** through the intervals.
- **If** `ans` is empty or the current start > last merged end, **push** the current interval.
- **Otherwise**, **update** the end of the last merged interval to the maximum of both ends.

## Edge Case
Empty input array. Handle with an initial check returning `{}`.

## Complexity
Time: O(N log N)
Space: O(N)

## Revision Note
Sort -> If no overlap, push -> If overlap, update end: `max(ans.back()[1], arr[i][1])`.
