# Coin Change II

## Key Idea
The problem asks for the total number of ways to make up a given amount using a given set of coin denominations (with infinite supply of each coin). We can solve this using space-optimized dynamic programming by keeping track of the previous row (`prev`) and current row (`cur`) representing the number of ways.

## Pattern
Dynamic Programming / Unbounded Knapsack / Space Optimization

## Approach
- **Initialization**: Create a 1D array `prev` of size `amount + 1` initialized to 0.
- **Base Case**: For the first coin (`coins[0]`), if a target `i` is a multiple of this coin (`i % coins[0] == 0`), there is 1 way to form it. Set `prev[i] = 1`.
- **Iteration**: For each subsequent coin from index 1 to $N-1$:
  - Create a new 1D array `cur` of size `amount + 1` initialized to 0.
  - Loop through all target amounts from 0 to `amount`.
  - **Not Taken**: Number of ways without the current coin is `prev[target]`.
  - **Taken**: If the current coin value is $\le$ target, the number of ways using the current coin is `cur[target - coins[ind]]` (we use `cur` because we can pick the same coin multiple times).
  - Update `cur[target] = (notTaken + taken) % MOD`.
  - Set `prev = cur` after the inner loop.
- **Return**: The answer is stored in `prev[amount]`.

## Edge Case
Amount is 0 (returns 1). No coins can form the amount (returns 0).

## Complexity
Time: O(N \times \text{amount}) where $N$ is the number of coins.
Space: O(\text{amount}) for the two 1D arrays `prev` and `cur`.

## Revision Note
Unbounded knapsack space optimization. Base case: `if (i % coins[0] == 0) prev[i] = 1`. DP step: `notTaken = prev[target]`, `taken = cur[target - coins[ind]]` (use `cur` for taken!). `cur[target] = notTaken + taken`.
