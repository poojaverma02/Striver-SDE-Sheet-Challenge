# Minimum Coins

## Key Idea
Use Dynamic Programming instead of a Greedy approach to find the minimum coins required, building up the solution for every amount from 1 to the target amount.

## Pattern
Dynamic Programming

## Approach
- **Initialize** a DP array `dp` of size `amount + 1` with `INT_MAX`, setting `dp[0] = 0`.
- **Iterate** over every amount from 1 to the target amount.
- **For each** amount, try all given coin denominations.
- **Update** `dp[i]` with the minimum of its current value or `dp[i - coin] + 1` if the subproblem is reachable.

## Edge Case
Target amount cannot be formed by any combination of coins.

## Complexity
Time: O(amount × n)
Space: O(amount)

## Revision Note
DP array size `amount + 1` initialized to `INT_MAX` -> `dp[0] = 0` -> `dp[i] = min(dp[i], dp[i - coin] + 1)`.
