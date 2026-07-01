# Minimum Insertions to Make String Palindrome

## Key Idea
The minimum number of insertions required to make a string a palindrome is equal to the string's length minus the length of its Longest Palindromic Subsequence (LPS).

## Pattern
Dynamic Programming / Longest Common Subsequence (LCS)

## Approach
- **Find LPS**: The Longest Palindromic Subsequence of a string `S` is equivalent to the Longest Common Subsequence (LCS) of `S` and its reverse `R`.
- **LCS Implementation**: Use a space-optimized 1D DP array to calculate the LCS of `S` and `R`. If characters match, `cur[ind2] = 1 + prev[ind2 - 1]`. Otherwise, `cur[ind2] = max(prev[ind2], cur[ind2 - 1])`.
- **Calculate Insertions**: Subtract the length of the computed LPS from the original length of the string to get the minimum number of insertions required.

## Edge Case
String is already a palindrome (0 insertions), or all characters are distinct.

## Complexity
Time: O(N^2) where N is the length of the string.
Space: O(N) using space-optimized DP.

## Revision Note
`reverse(s)` to get `t` -> find `LCS(s, t)` using 1D space optimized DP -> min insertions = `n - LCS(s, t)`.
