# Word Break

## Key Idea
Use Dynamic Programming to track if prefixes of the string can be fully segmented into dictionary words, avoiding redundant checks by only considering lengths up to the longest dictionary word.

## Pattern
Dynamic Programming

## Approach
- **Convert** the word dictionary into a hash set for $O(1)$ lookups and find the maximum word length `maxLen`.
- **Initialize** a DP array of size `n + 1` with `false`, setting `dp[0] = true` to signify an empty prefix.
- **Iterate** through the string indices `i`. If `dp[i]` is true, the prefix is valid.
- **Extend**: From position `i`, try extending by checking substrings of length 1 up to `maxLen`. If the substring is in the dictionary, set `dp[i + len] = true`.

## Edge Case
String cannot be segmented, or dictionary contains single-character strings matching parts of the word.

## Complexity
Time: O(n × L)
Space: O(n)

## Revision Note
Store words in set -> find `maxLen` -> `dp[0] = true` -> loop `i` over string -> if `dp[i]`, loop `len` up to `maxLen` -> if `dict.count(substr)`, `dp[i + len] = true`.
