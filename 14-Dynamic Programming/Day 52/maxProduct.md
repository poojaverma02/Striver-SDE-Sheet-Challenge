# Maximum Product Subarray

## Key Idea
Finding the maximum product subarray can be tricky because multiplying two negative numbers yields a positive product. By traversing the array from left to right (prefix product) and right to left (suffix product), we can effectively capture the maximum product even when negative numbers or zeros are present.

## Pattern
Array / Math / Prefix & Suffix

## Approach
- **Initialization**: Initialize `prefix = 1`, `suffix = 1`, and `ans = INT_MIN`.
- **Iteration**: Loop through the array from $i = 0$ to $N-1$.
  - If `prefix` becomes $0$ (due to a $0$ in the array), reset it to $1$.
  - If `suffix` becomes $0$, reset it to $1$.
  - Multiply `prefix` by `nums[i]`.
  - Multiply `suffix` by `nums[N - i - 1]`.
  - Update `ans` with the maximum of `ans`, `prefix`, and `suffix`.
- **Return**: The maximum product stored in `ans`.

## Edge Case
Array with a single negative element. Array containing zeros. Array with all negative elements.

## Complexity
Time: O(N) as we traverse the array exactly once.
Space: O(1) as we only use a few variables for tracking the products.

## Revision Note
Use `prefix` and `suffix` running products. If either hits 0, reset it to 1. At each step, multiply by current element (from front for prefix, from back for suffix) and take `max(ans, max(prefix, suffix))`.
