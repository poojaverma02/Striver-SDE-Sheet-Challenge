# Roman to Integer

## Key Idea
Iterate through the Roman numeral string. If a symbol is smaller than the next symbol, subtract its value. Otherwise, add its value to the total.

## Pattern
Hash Map / Math

## Approach
- **Map Values**: Create a hash map storing the integer values for each Roman symbol (`I=1, V=5, X=10`, etc.).
- **Iterate**: Loop through each character `s[i]` in the string.
- **Subtractive Case**: If `i + 1 < n` and the value of `s[i]` is less than the value of `s[i+1]` (e.g., `IV`), subtract `s[i]`'s value from the total.
- **Additive Case**: Otherwise, add `s[i]`'s value to the total.
- **Return Total**: The total will be the final integer representation.

## Edge Case
Single character string, or strings entirely made of subtractive cases.

## Complexity
Time: O(N) where N is the length of the string.
Space: O(1)

## Revision Note
Map of char to int -> loop string -> if `val[i] < val[i+1]`, `total -= val[i]` -> else `total += val[i]`.
