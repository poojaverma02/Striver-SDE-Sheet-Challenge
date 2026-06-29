# Stock Span Problem

## Key Idea
Use a monotonic decreasing stack to find the Previous Greater Element (PGE) for each stock price. The span is simply the difference between the current index and the index of the PGE.

## Pattern
Monotonic Stack

## Approach
- **Traverse**: Loop through the array from left to right.
- **Maintain Stack**: Use a stack to store the indices of elements in a monotonic decreasing order. For each element `arr[i]`, pop indices from the stack while the elements at those indices are `<= arr[i]`.
- **Calculate Span**: If the stack becomes empty, it means there is no previous greater element, so the span is `i - (-1) = i + 1`. If not empty, the span is `i - st.top()`.
- **Push**: Push the current index `i` onto the stack for future elements.

## Edge Case
Prices strictly increasing (span increases every day) or strictly decreasing (span is always 1).

## Complexity
Time: O(N)
Space: O(N)

## Revision Note
Find PGE index using monotonic decreasing stack -> `span = i - PGE[i]` -> if stack is empty, `PGE[i] = -1`.
