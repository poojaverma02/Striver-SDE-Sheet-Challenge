# Largest Rectangle in Histogram

## Key Idea
Use a monotonic stack to efficiently find the Previous Smaller Element (PSE) and Next Smaller Element (NSE) for each bar in a single pass to calculate the maximum area.

## Pattern
Monotonic Stack

## Approach
- **Iterate** through the histogram.
- **Maintain Stack**: Keep indices of bars in a strictly increasing height order in the stack.
- **Calculate Area**: If the current bar is shorter than the bar at the top of the stack, pop the top. For the popped bar, the current index is the NSE, and the new top of the stack is the PSE. The width is `(nse - pse - 1)`. Calculate area and update the maximum.
- **Remaining Elements**: After the loop, pop remaining elements with `nse = n` and calculate their areas similarly.

## Edge Case
All bars have the same height, or heights are in descending order.

## Complexity
Time: O(N)
Space: O(N)

## Revision Note
Monotonic increasing stack -> pop when `arr[top] >= arr[i]` -> `nse = i`, `pse = st.empty() ? -1 : st.top()` -> `width = nse - pse - 1` -> push `i`.
