# Matrix Chain Multiplication

## Key Idea
The Matrix Chain Multiplication problem seeks to find the most efficient way to multiply a given sequence of matrices. The problem is not actually to perform the multiplications, but merely to decide the sequence of the matrix multiplications involved. We use dynamic programming (tabulation) to calculate the minimum cost for chains of increasing lengths.

## Pattern
Dynamic Programming / Matrix Chain Multiplication

## Approach
- **Initialization**: Create a 2D `dp` array of size $N \times N$, initialized to infinity (`INT_MAX`).
- **Base Case**: A single matrix needs no multiplication, so set `dp[i][i] = 0` for all $i$ from 1 to $N-1$.
- **Nested Loops**: 
  - Iterate over the `length` of the chain from $2$ to $N-1$.
  - Iterate over the start index `i` from $1$ to $N - length$.
  - Calculate the end index `j = i + length - 1`.
  - For each subchain from $i$ to $j$, try every possible partition point `k` from $i$ to $j-1$.
  - Calculate the cost to multiply the matrices split at `k`: `cost = dp[i][k] + dp[k+1][j] + nums[i-1] * nums[k] * nums[j]`.
  - Update `dp[i][j]` with the minimum cost found.
- **Return**: The minimum cost to multiply matrices from index $1$ to $N-1$ is stored in `dp[1][N-1]`.

## Edge Case
Only one matrix (handled by base case). Only two matrices (length 2 directly calculates the cost).

## Complexity
Time: O(N^3) due to three nested loops (length, start index, partition point).
Space: O(N^2) to store the 2D `dp` table.

## Revision Note
3 nested loops: `len` (2 to N-1), `i` (1 to N-len), `k` (i to j-1). Cost formula: `dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j]`. Result is in `dp[1][N-1]`.
