# Find Missing and Repeating Numbers

## Key Idea
Use mathematical formulas for the sum of first `N` natural numbers and sum of their squares to form two equations and solve for the missing and repeating numbers.

## Pattern
Math

## Approach
- **Calculate** expected sum `sn = N*(N+1)/2` and expected squared sum `s2n = N*(N+1)*(2N+1)/6`.
- **Calculate** the actual sum `s` and actual squared sum `s2` from the array.
- **Find** `val1 = s - sn` (which is `x - y`).
- **Find** `val2 = s2 - s2n` (which is `x^2 - y^2`).
- **Simplify** `val2 = val2 / val1` to get `x + y`.
- **Solve** for `x` (repeating) and `y` (missing).

## Edge Case
Large values can cause integer overflow. Using `long long` for all math operations prevents this.

## Complexity
Time: O(N)
Space: O(1)

## Revision Note
`val1 = x - y`, `val2 = x^2 - y^2`. Divide to get `x + y`. Solve equations. Use `long long`!
