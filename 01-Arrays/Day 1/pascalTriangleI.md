# Pascal's Triangle (Specific Element)

## Key Idea
The element at row `r` and column `c` (1-indexed) in Pascal's Triangle is given by the combination formula `(r-1)C(c-1)`.

## Pattern
Math (Combinatorics)

## Approach
- **Use** the formula `nCr(r - 1, c - 1)`.
- **Optimize** `nCr` calculation by running a loop `i` from `0` to `r-1`.
- **Multiply** `res` by `(n - i)` and **divide** by `(i + 1)` in each iteration.

## Edge Case
`r == 1` or `c == 1`. The optimized `nCr` handles this efficiently.

## Complexity
Time: O(C)
Space: O(1)

## Revision Note
Value is `(r-1)C(c-1)` -> Calculate `nCr` in O(r) using `res = res * (n - i) / (i + 1)`.
