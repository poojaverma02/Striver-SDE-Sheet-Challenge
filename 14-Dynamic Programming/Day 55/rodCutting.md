# Rod Cutting Problem

## Key Idea
The problem asks for the maximum profit obtained by cutting a rod of length $n$ and selling the pieces. This is an Unbounded Knapsack variation where the weights are the lengths of the cuts and the values are the prices. We can optimize the DP space using two 1D arrays (`prev` and `cur`).

## Pattern
Dynamic Programming / Unbounded Knapsack / Space Optimization

## Approach
- **Initialization**: Create two 1D arrays `prev` and `cur` of size $n+1$ initialized to $0$.
- **Base Case**: The first piece has length 1. For any given rod length `length`, we can only cut it into pieces of length 1. Thus, `prev[length] = price[0] * length`.
- **Iteration**: For each piece index `ind` from $1$ to $n-1$:
  - The length of the current piece is `rodLength = ind + 1`.
  - Loop through all rod lengths `length` from $1$ to $n$.
  - **Not Taken**: `notTaken = prev[length]`.
  - **Taken**: `taken = INT_MIN`. If `rodLength <= length`, we can take the piece and add its price to the profit of the remaining length: `taken = price[ind] + cur[length - rodLength]`. (We use `cur` because we have infinite supply of this cut).
  - Update `cur[length] = max(notTaken, taken)`.
  - Update `prev = cur`.
- **Return**: The maximum profit is stored in `prev[n]`.

## Edge Case
Rod length is 0 (returns 0). All prices are the same.

## Complexity
Time: O(N^2) as we loop through $N$ pieces and for each, we check up to rod length $N$.
Space: O(N) for the two 1D arrays.

## Revision Note
Unbounded knapsack approach. Base case: `prev[L] = price[0] * L`. DP step: `notTaken = prev[L]`, `taken = price[ind] + cur[L - rodLength]`. `cur[L] = max(notTaken, taken)`. Use `cur` for unboundedness!
