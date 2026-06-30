# Longest Common Prefix

## Key Idea
Instead of comparing every string with each other, sort the array lexicographically. The first and last strings in the sorted array are the most different, so their common prefix is the longest common prefix for all strings in the array.

## Pattern
Sorting / String Comparison

## Approach
- **Sort**: Sort the array of strings lexicographically.
- **Extremes**: Grab the first string and the last string in the sorted array.
- **Compare Characters**: Iterate through the characters of these two extreme strings up to the length of the shorter one.
- **Build Prefix**: If the characters match, append them to the answer string. If a mismatch occurs, break immediately and return the answer.

## Edge Case
Empty input array or an array containing an empty string.

## Complexity
Time: O(N \cdot M \log N) for sorting, plus O(M) for comparison.
Space: O(M) for the result string.

## Revision Note
Sort the array -> compare `str[0]` and `str[n-1]` char by char -> stop at first mismatch -> return the matching prefix.
