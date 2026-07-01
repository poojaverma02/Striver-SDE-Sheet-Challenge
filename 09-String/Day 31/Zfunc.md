# Z-Function

## Key Idea
Compute the Z-array for a combined string (`pattern + '$' + text`) where `Z[i]` stores the length of the longest substring starting at `i` that matches the prefix of the string. A match is found when `Z[i]` equals the pattern length.

## Pattern
String Matching / Z-Algorithm

## Approach
- **Concatenation**: Combine the pattern and text with a delimiter as `pattern + '$' + text`.
- **Compute Z-array**: Use a sliding window `[left, right]` that represents the rightmost substring matching the prefix.
  - If `i > right`, calculate `Z[i]` naively by comparing characters and update the window.
  - If `i <= right`, use the previously computed values (`Z[i - left]`). If `Z[i - left]` is strictly less than the remaining window `right - i + 1`, `Z[i] = Z[i - left]`. Otherwise, start matching naively from the right edge.
- **Find Matches**: Iterate over the Z-array after the delimiter. If `Z[i]` equals the pattern length, add `i - (pattern.length() + 1)` to the result.

## Edge Case
Pattern length is greater than text length, or pattern does not exist in the text.

## Complexity
Time: O(N + M) where N is text length and M is pattern length.
Space: O(N + M) for the combined string and Z-array.

## Revision Note
`string s = pat + '$' + txt` -> Compute Z-array maintaining window `[left, right]` -> loop through `s`: if `Z[i] == m`, `ans.push_back(i - (m+1))`.
