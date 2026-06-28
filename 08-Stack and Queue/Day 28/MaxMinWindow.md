# Maximum of Minimum for Every Window Size

## Key Idea
Find the previous and next smaller elements for each element to determine the largest window where it acts as the minimum. Then, use this to fill an array with the maximum values for each window size.

## Pattern
Monotonic Stack

## Approach
- **Next/Prev Smaller**: Use a monotonic increasing stack to compute the index of the Previous Smaller Element (`left[]`) and Next Smaller Element (`right[]`) for each element in $O(N)$ time.
- **Max of Mins**: For each element, the maximum window size where it is the minimum is `len = right[i] - left[i] - 1`. Update `ans[len] = max(ans[len], arr[i])`.
- **Fill Gaps**: Some window sizes might not have a direct maximum minimum. Since a smaller window can always take the answer of a larger window, iterate backwards: `ans[len] = max(ans[len], ans[len+1])`.
- **Format Output**: Extract the values from index `1` to `N` into the final result array.

## Edge Case
All elements are identical, or elements are strictly increasing/decreasing.

## Complexity
Time: O(N)
Space: O(N)

## Revision Note
Monotonic Stack for PSE and NSE -> `len = right[i] - left[i] - 1` -> `ans[len] = max(ans[len], arr[i])` -> `ans[len] = max(ans[len], ans[len+1])` backwards.
