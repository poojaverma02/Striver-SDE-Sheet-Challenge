# Super Egg Drop

## Key Idea
Instead of finding the minimum number of attempts given $n$ eggs and $k$ floors directly (which can be $O(K \times N^2)$), we reverse the problem: What is the maximum number of floors we can check with $n$ eggs and $m$ moves? The DP state `dp[i]` stores the max floors we can test with $i$ eggs in the current number of moves. We increment moves until `dp[n] >= k`.

## Pattern
Dynamic Programming / Math

## Approach
- **Initialization**: Create a 1D `dp` array of size $n + 1$ initialized to $0$. Initialize `moves = 0`.
- **Iteration**: While `dp[n] < k`:
  - Increment `moves`.
  - Loop backwards from $n$ down to 1.
  - The number of floors we can check with $i$ eggs and the current `moves` is the floors checked if the egg breaks (using $i-1$ eggs and `moves-1`) plus the floors checked if it doesn't break (using $i$ eggs and `moves-1`), plus 1 for the current floor.
  - So, `dp[i] = dp[i] + dp[i - 1] + 1`.
- **Return**: Once `dp[n] >= k`, return the accumulated `moves`.

## Edge Case
1 egg ($k$ moves needed). 0 floors (0 moves).

## Complexity
Time: O(K \log K) or more specifically $O(n \times m)$ where $m$ is the minimum moves needed (bounded by $\log k$ when $n$ is large).
Space: O(n) for the 1D DP array.

## Revision Note
Reverse the problem: Max floors with $i$ eggs in $m$ moves. `dp[i] = dp[i] + dp[i-1] + 1`. Loop `moves` until `dp[n] >= k`. Traverse `dp` backwards to use previous step's values.
