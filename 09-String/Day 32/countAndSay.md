# Count and Say

## Key Idea
Generate the $N^{th}$ term in the sequence by finding the $(N-1)^{th}$ term recursively and encoding it using Run-Length Encoding (RLE).

## Pattern
Recursion / String Manipulation

## Approach
- **Base Case**: If `n == 1`, return `"1"`.
- **Recursion**: Recursively call `countAndSay(n - 1)` to get the previous string.
- **Run-Length Encoding**: Iterate through the characters of the previous string starting from index `1`. Maintain a `count` for the current sequence of identical characters.
- **Record**: When the character changes (run breaks), push the `count` (as a char) and the character itself to the answer string, then reset `count`.
- **Flush**: After the loop, explicitly push the final count and character for the last run.

## Edge Case
$N=1$, which serves as the starting point.

## Complexity
Time: O(N \times L) where L is the average length of the strings.
Space: O(N + L) for the recursion stack and resulting string.

## Revision Note
Base case `n=1` returns `"1"` -> recurse `prev = f(n-1)` -> loop `prev` from `1` to `len`: if same char `count++`, else `ans.push(count)`, `ans.push(char)`, reset `count` -> flush last run after loop.
