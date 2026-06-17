# Combination Sum

## Key Idea
Use recursion to explore all possible combinations by either picking a candidate multiple times or skipping it, backtracking whenever the sum exceeds the target.

## Pattern
Recursion / Backtracking

## Approach
- **Base Cases**: If the remaining target sum is `0`, a valid combination is found. If the sum becomes negative or no candidates are left, return.
- **Take**: Include the current candidate `candidates[i]` in the combination and recursively call for the same index `i` with the reduced sum.
- **Backtrack**: Remove the last added candidate from the combination.
- **Skip**: Move to the next candidate `i-1` and recursively call with the same remaining sum.

## Edge Case
No combination can form the target sum.

## Complexity
Time: O(K*N(Target/m))
Space: O(Target/m)

## Revision Note
Include element & stay on same index -> backtrack -> exclude element & move to next index.
