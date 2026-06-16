# Implement Pow(x, n)

## Key Idea
Use Binary Exponentiation. Represent the exponent `n` in binary and multiply the base `x` at set bit positions. Square the base at every step while halving the exponent.

## Pattern
Binary Exponentiation

## Approach
- **Handle** negative exponents by inverting `x` (`1.0 / x`) and converting the exponent `n` to a positive value.
- **Initialize** `result = 1.0`.
- **Loop** while the exponent `num > 0`:
  - If `num` is odd, **multiply** `result` by `x`.
  - **Square** `x` (`x *= x`).
  - **Divide** `num` by 2.
- **Return** `result`.

## Edge Case
`n = INT_MIN`. Converting `-n` directly to positive causes integer overflow. Cast to `long long` first.

## Complexity
Time: O(log N)
Space: O(1)

## Revision Note
Binary exponentiation: odd exponent -> multiply result by x. Always square x and divide exponent by 2. Cast `n` to `long long`.
