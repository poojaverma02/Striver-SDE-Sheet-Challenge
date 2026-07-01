# String to Integer (atoi)

## Key Idea
Parse a string into an integer by simulating the standard `atoi` function: skip leading whitespaces, handle an optional sign, process contiguous digits, and clamp the result to the 32-bit signed integer limits to avoid overflow.

## Pattern
String Parsing / Math

## Approach
- **Whitespace**: Advance the index to skip any leading space characters (`' '`).
- **Sign**: Check for an optional `'+'` or `'-'` character and store the sign (+1 or -1). Advance the index if a sign is found.
- **Convert Digits**: Read characters while they are valid digits (`isdigit`). Build the number using `result = result * 10 + (char - '0')`.
- **Overflow Handling**: Use a `long long` for the intermediate result. At each step, check if `result * sign` exceeds `INT_MAX` (return `INT_MAX`) or drops below `INT_MIN` (return `INT_MIN`).
- **Return**: Multiply the computed numerical value by the sign and return.

## Edge Case
Strings with leading characters that are not numbers/signs, inputs causing overflow/underflow, or empty strings.

## Complexity
Time: O(N) where N is the length of the string.
Space: O(1)

## Revision Note
Skip spaces -> check sign -> loop `isdigit` -> `res = res * 10 + (c - '0')` -> check overflow with `INT_MAX` and `INT_MIN` -> return `res * sign`.
