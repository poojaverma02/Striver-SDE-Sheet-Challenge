# Power Set

## Key Idea
The Power Set of a set is the set of all its possible subsets (including the empty set and the set itself). We can generate all $2^N$ subsets using recursion / backtracking by making a binary decision at each index $i$: either exclude `nums[i]` or include `nums[i]` in the current subset.

## Pattern
Backtracking / Recursion / Subset Generation

## Approach
- **Recursive Helper**: `func(ind, n, nums, arr, ans)`
  - **Base Case**: If `ind == n`, we have considered all elements. Add a copy of `arr` to `ans` and return.
  - **Exclude Option**: Call `func(ind + 1, n, nums, arr, ans)` without modifying `arr`.
  - **Include Option**: Push `nums[ind]` into `arr`, call `func(ind + 1, n, nums, arr, ans)`.
  - **Backtrack**: Pop `nums[ind]` from `arr` (`arr.pop_back()`).
- **Main Function**: Initialize `ans` and `arr`, call `func(0, n, nums, arr, ans)`, and return `ans`.

## Edge Case
Empty array (returns `[[]]`). Single element array (returns `[[], [nums[0]]]`).

## Complexity
Time: O(2^N) as there are $2^N$ total subsets generated.
Space: O(N \times 2^N) for storing all $2^N$ subsets of average length $N/2$, plus $O(N)$ for recursion call stack depth.

## Revision Note
Backtracking for subsets. Base case: `ind == n` $\rightarrow$ `ans.push_back(arr)`. Two choices: 1. Exclude `func(ind+1)`. 2. Include: `arr.push_back(nums[ind])`, `func(ind+1)`, backtrack `arr.pop_back()`.
