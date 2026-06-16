# N Meetings in One Room

## Key Idea
Sort the meetings based on their end times and greedily pick the meeting that finishes earliest, as it leaves the maximum possible time for future meetings.

## Pattern
Greedy Algorithm / Sorting

## Approach
- **Pair** the start and end times of each meeting.
- **Sort** the pairs primarily by their end times in ascending order.
- **Initialize** the count of meetings and a variable tracking the `freeTime` (end time of the last attended meeting).
- **Iterate** through the sorted meetings, and if a meeting starts strictly after `freeTime`, attend it and update `freeTime`.

## Edge Case
Meetings starting precisely when another ends (usually allowed, depending on problem constraints).

## Complexity
Time: O(N log N)
Space: O(N)

## Revision Note
Sort by end time -> pick first -> if `next.start > current.end`, pick it and update `current.end`.
