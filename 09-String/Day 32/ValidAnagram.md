# Valid Anagram

## Key Idea
Two strings are anagrams if they have exactly the same characters with the same frequencies. Use a frequency array to count characters in both strings simultaneously.

## Pattern
Hash Map / Frequency Array

## Approach
- **Length Check**: If the two strings have different lengths, they cannot be anagrams.
- **Frequency Array**: Create an array of size 26 (for lowercase English letters) initialized to `0`.
- **Count**: Iterate through both strings. For string `s`, increment the count for the character. For string `t`, decrement the count for the character.
- **Verify**: Iterate through the frequency array. If any count is not `0`, return false. If all are `0`, return true.

## Edge Case
Strings of unequal length or empty strings.

## Complexity
Time: O(N) where N is the length of the string.
Space: O(1) (fixed array of size 26).

## Revision Note
Count frequency in array of size 26 -> increment for `s`, decrement for `t` -> loop array, return false if any non-zero -> return true.
