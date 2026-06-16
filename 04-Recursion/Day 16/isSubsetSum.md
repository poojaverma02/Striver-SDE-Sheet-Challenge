# Subset Sum Equals to Target

## Key Idea
Use a 1D DP array to track achievable subset sums, updating it backwards for each element to avoid reusing the same element in a single subset.

## Pattern
Dynamic Programming / 0/1 Knapsack

## Approach
- **Initialize** a DP array `dp` of size `target + 1` with `false`, setting `dp[0] = true`.
- **Iterate** through each element in the input array.
- **Traverse** the DP array backwards from `target` down to the current element's value.
- **Update** `dp[t] = true` if `dp[t - arr[i]]` is true.

## Edge Case
Target is 0 (always true) or array elements are all larger than target.

## Complexity
Time: O(n × target)
Space: O(target)

## Revision Note
1D DP array -> `dp[0] = true` -> loop array -> loop `target` down to `arr[i]` -> `dp[t] = dp[t] || dp[t - arr[i]]`.
