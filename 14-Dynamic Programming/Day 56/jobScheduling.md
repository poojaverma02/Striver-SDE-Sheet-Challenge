# Maximum Profit in Job Scheduling

## Key Idea
To maximize profit from non-overlapping jobs, we sort the jobs by their end times. For each job, we decide whether to include it or exclude it. If included, we add its profit to the maximum profit obtainable from the latest non-conflicting job before it (found via binary search).

## Pattern
Dynamic Programming / Binary Search / Interval Scheduling

## Approach
- **Sort Jobs**: Combine `startTime`, `endTime`, and `profit` into a list of jobs and sort them by `endTime`.
- **Binary Search**: Write `latestNonConflict(jobs, i)` to find the largest index $l < i$ where `jobs[l].end <= jobs[i].start` using binary search in $O(\log N)$ time.
- **DP State & Transition**:
  - `dp[i]` represents the max profit using a subset of the first $i+1$ jobs.
  - For job $i$: `inclProf = jobs[i].profit + (l != -1 ? dp[l] : 0)`.
  - `dp[i] = max(inclProf, dp[i-1])`.
- **Return**: `dp[n-1]`.

## Edge Case
No non-conflicting job exists ($l = -1$). Single job.

## Complexity
Time: O(N \log N) for sorting and performing $N$ binary searches.
Space: O(N) for storing the job objects and the DP array.

## Revision Note
Sort jobs by `endTime`. For job $i$, use binary search to find last non-overlapping job $l$ (`end <= start[i]`). Transition: `dp[i] = max(dp[i-1], jobs[i].profit + dp[l])`.
