# Minimum Platforms

## Key Idea
Separate the arrival and departure times, sort them individually, and simulate the train station events using two pointers to count the platforms needed at any point.

## Pattern
Greedy Algorithm / Two Pointers

## Approach
- **Sort** the arrival and departure arrays independently.
- **Initialize** two pointers for arrival and departure, keeping a running count of platforms.
- **Traverse**:
  - If a train arrives (`Arrival[i] <= Departure[j]`), increment platform count and move arrival pointer.
  - If a train departs, decrement platform count and move departure pointer.
- **Track** the maximum number of platforms needed at any time.

## Edge Case
Multiple trains arriving and departing at the exact same time.

## Complexity
Time: O(N log N)
Space: O(1)

## Revision Note
Sort both arrays -> two pointers `i, j` -> if `arr[i] <= dep[j]`, `count++` -> else `count--` -> track max count.
