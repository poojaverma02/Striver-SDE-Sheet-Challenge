# Longest Palindromic Substring

## Key Idea
Expand outward from every possible center (both single characters and between two characters) to find the longest palindromic substring in $O(N^2)$ time with $O(1)$ space.

## Pattern
Expand Around Center

## Approach
- **Iterate**: Loop through each character index `i` in the string.
- **Odd Length Palindromes**: Assume `i` is the center of an odd-length palindrome (e.g., `"aba"`). Expand left and right as long as characters match.
- **Even Length Palindromes**: Assume the center is between `i` and `i+1` (e.g., `"abba"`). Expand left and right as long as characters match.
- **Track Maximum**: Keep track of the start and end indices of the longest palindrome found across all centers.
- **Extract Substring**: Use the start and end indices to extract the longest palindromic substring.

## Edge Case
Empty string or string with all unique characters.

## Complexity
Time: O(N²)
Space: O(1)

## Revision Note
Iterate `i` from 0 to N-1 -> expand around `(i, i)` -> expand around `(i, i+1)` -> track max length window `(start, end)` -> return `s.substr(start, length)`.
