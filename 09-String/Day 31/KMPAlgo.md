# KMP Algorithm (LPS Array)

## Key Idea
Use the Longest Prefix Suffix (LPS) array to avoid redundant comparisons when searching for a pattern in a text, achieving linear time string matching.

## Pattern
String Matching / KMP

## Approach
- **Concatenation**: Combine the pattern and text with a delimiter (e.g., `$`) as `pattern + '$' + text`.
- **Compute LPS**: Iterate over the combined string to compute the LPS array. For a mismatch after some matches, use the previously computed LPS values to safely skip redundant character comparisons (`j = LPS[j-1]`).
- **Find Matches**: Iterate over the computed LPS array starting after the delimiter. Whenever `LPS[i]` equals the length of the pattern, it means a full match was found. Calculate and store the starting index in the original text as `i - 2 * pattern.size()`.

## Edge Case
Pattern length is greater than text length, or pattern does not exist in the text.

## Complexity
Time: O(N + M) where N is text length and M is pattern length.
Space: O(N + M) for the combined string and LPS array.

## Revision Note
`string s = pat + '$' + txt` -> Compute LPS array for `s` -> loop through `s`: if `LPS[i] == m`, `ans.push_back(i - 2*m)`.
