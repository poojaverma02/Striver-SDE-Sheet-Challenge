# Job Sequencing Problem

## Key Idea
Sort the jobs in descending order of their profit and assign each job to the latest possible free slot before its deadline.

## Pattern
Greedy Algorithm / Sorting

## Approach
- **Sort** the jobs by profit in descending order.
- **Find** the maximum deadline to determine the total number of slots available.
- **Initialize** an array to keep track of filled time slots.
- **Iterate** through the sorted jobs and place each job in the latest available slot from its `deadline - 1` backwards to 0.

## Edge Case
Jobs with the same profit or deadlines that conflict heavily.

## Complexity
Time: O(N log N + N × M)
Space: O(M)

## Revision Note
Sort by max profit -> find max deadline `M` -> array of size `M` -> place job as late as possible `for(j = deadline-1; j>=0)`.
