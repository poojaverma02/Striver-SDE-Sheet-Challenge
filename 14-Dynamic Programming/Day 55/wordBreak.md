# Word Break

## Key Idea
Given a string and a dictionary of words, we need to find if the string can be fully segmented into dictionary words. We can solve this with a boolean 1D DP array, where `dp[i]` represents whether the prefix of length `i` can be segmented.

## Pattern
Dynamic Programming / String / Hash Set

## Approach
- **Initialization**: Convert `wordDict` into an `unordered_set` for $O(1)$ lookups. Create a `dp` array of size $n+1$ initialized to `false`. Set `dp[0] = true` (empty prefix is always segmentable).
- **Optimization**: Find `maxLen`, the length of the longest word in the dictionary, to bound the inner loop and avoid unnecessary substring checks.
- **Iteration**: For every starting index `i` from $0$ to $n-1$:
  - If `!dp[i]`, the prefix up to `i` is not segmentable, so we can't extend it. `continue`.
  - Try every possible word length `len` from $1$ up to `maxLen` (ensuring `i + len <= n`).
  - Check if the substring `s.substr(i, len)` exists in the dictionary.
  - If it does, mark the extended prefix as reachable: `dp[i + len] = true`.
- **Return**: The boolean value in `dp[n]`.

## Edge Case
Empty string (handled by `dp[0] = true`). Substring exists but dictionary contains no such words.

## Complexity
Time: O(n \times L) where $n$ is string length and $L$ is the max word length in the dictionary.
Space: O(n + W) where $W$ is the dictionary space for the hash set.

## Revision Note
1D DP array. `dp[i] = true` if prefix of length `i` can be segmented. If `dp[i]` is true, check all substrings `s[i...i+len]`. If found in dict, `dp[i+len] = true`. Return `dp[n]`.
