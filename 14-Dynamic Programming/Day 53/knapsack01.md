# 0/1 Knapsack

## Key Idea
The 0/1 Knapsack problem asks for the maximum value we can obtain by picking a subset of items such that their total weight doesn't exceed a given capacity $W$. Using dynamic programming, we can optimize space by using a single 1D array (`prev`) and traversing the capacities in reverse order.

## Pattern
Dynamic Programming / Knapsack / Space Optimization

## Approach
- **Initialization**: Create a 1D array `prev` of size $W+1$ initialized to $0$.
- **Base Case**: For the first item (`ind = 0`), fill `prev[cap]` with `val[0]` for all capacities `cap` $\ge \text{wt}[0]$.
- **Iteration**: For each subsequent item `ind` from $1$ to $N-1$:
  - Loop through capacities `cap` from $W$ down to $0$ (reverse order to ensure we only use the previous item's states, simulating the `prev` array without actually allocating a new `cur` array).
  - **Not Taken**: The value if we skip the item is `prev[cap]`.
  - **Taken**: The value if we include the item is `val[ind] + prev[cap - wt[ind]]` (only if `wt[ind] <= cap`).
  - Update `prev[cap] = \max(\text{notTaken}, \text{taken})`.
- **Return**: The answer is `prev[W]`.

## Edge Case
Capacity is 0 (returns 0). No items fit in the knapsack.

## Complexity
Time: O(N \times W) where $N$ is the number of items and $W$ is the maximum capacity.
Space: O(W) using a single 1D array.

## Revision Note
1D array DP space optimization. Traverse capacity backwards `for(cap = W to 0)`. `notTaken = prev[cap]`, `taken = val[i] + prev[cap - wt[i]]`. `prev[cap] = max(notTaken, taken)`.
