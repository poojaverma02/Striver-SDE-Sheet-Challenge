# Reverse Words in a String

## Key Idea
Reverse the entire string first, then compact the string in-place by ignoring extra spaces, and finally reverse each individual word back to its correct spelling.

## Pattern
Two Pointers / In-place Reversal

## Approach
- **Reverse All**: Reverse the entire string $O(N)$.
- **Compact & Parse**: Use two pointers (`i` for writing, `j` for reading). Skip leading/multiple spaces. When a word is found, copy it character by character using `s[i++] = s[j++]`.
- **Reverse Individual Word**: Keep track of the start and end indices of the newly placed word, and reverse just that section to fix the spelling.
- **Add Space**: Append a single space after each word.
- **Cleanup**: Remove any trailing space from the very end and trim the string to the correct length `i`.

## Edge Case
String with only spaces, or multiple spaces between words, leading/trailing spaces.

## Complexity
Time: O(N)
Space: O(1)

## Revision Note
Reverse entire string -> skip spaces, copy word chars one by one (in-place compaction) -> reverse that specific word in-place -> add single space -> trim trailing space -> return `substr(0, i)`.
