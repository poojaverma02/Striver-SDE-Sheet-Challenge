# Subset Sum Equal to Target

## Key Idea
The problem asks if there is a subset of the given array whose sum equals the target. This is a classic 0/1 Knapsack variation. We can use space-optimized dynamic programming to solve it using two 1D boolean arrays (`prev` and `cur`).

## Pattern
Dynamic Programming / 0/1 Knapsack / Space Optimization

## Approach
- **Initialization**: Create a boolean array `prev` of size `target + 1` initialized to `false`.
- **Base Case**: 
  - A target sum of 0 is always possible by picking an empty subset. Set `prev[0] = true`.
  - If the first element `arr[0]` is $\le$ target, set `prev[arr[0]] = true`.
- **Iteration**: For each element `arr[ind]` from index 1 to $N-1$:
  - Create a boolean array `cur` initialized to `false`.
  - Set `cur[0] = true` (target 0 is always achievable).
  - Loop through all targets `i` from 1 to `target`.
  - **Not Taken**: `notTaken = prev[i]`.
  - **Taken**: `taken = false`. If `arr[ind] <= i`, `taken = prev[i - arr[ind]]`.
  - Update `cur[i] = notTaken || taken`.
  - Set `prev = cur`.
- **Return**: The answer is stored in `prev[target]`.

## Edge Case
Target is 0 (returns `true`). Single element array. Array sum is less than target (returns `false`).

## Complexity
Time: O(N \times \text{target}) where $N$ is the size of the array.
Space: O(\text{target}) for the two 1D boolean arrays.

## Revision Note
0/1 knapsack subset sum. Base cases: `prev[0] = true`, `prev[arr[0]] = true`. DP step: `notTaken = prev[i]`, `taken = prev[i - arr[ind]]`. `cur[i] = notTaken || taken`. Swap `prev = cur`.
