# Maximum Sum Increasing Subsequence

## Key Idea
Similar to the Longest Increasing Subsequence (LIS) problem, but instead of finding the length, we want to maximize the sum of the elements in the increasing subsequence. We use dynamic programming to store the maximum sum ending at each index.

## Pattern
Dynamic Programming / Subsequence

## Approach
- **Initialization**: Create a `dp` array of size $N$. Initialize `dp[i] = arr[i]` because the minimum sum of an increasing subsequence ending at index $i$ is the element itself (a subsequence of length 1).
- **Iteration**: 
  - Loop through all elements $i$ from $1$ to $N-1$.
  - For each element $i$, check all previous elements $j$ from $0$ to $i-1$.
  - If `arr[i] > arr[j]` (strictly increasing condition), update `dp[i]` as the maximum of its current value or `dp[j] + arr[i]`.
- **Return**: The maximum value in the entire `dp` array is the maximum sum of any increasing subsequence.

## Edge Case
Array with all negative numbers (returns the maximum single element). Array already sorted in descending order (each element is its own LIS).

## Complexity
Time: O(N^2) due to the two nested loops iterating over the array.
Space: O(N) for the `dp` array.

## Revision Note
Tabulation `dp` array initialized to `arr[i]`. Outer loop `i` from $1$ to $N-1$, inner loop `j` from $0$ to $i-1$. If `arr[i] > arr[j]`, `dp[i] = max(dp[i], dp[j] + arr[i])`. Return `max(dp)`.
