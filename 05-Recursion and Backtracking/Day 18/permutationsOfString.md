# Permutations of a String

## Key Idea
Sort the string first to easily skip duplicate characters, then use backtracking with a boolean `used` array to build all unique permutations lexicographically.

## Pattern
Recursion / Backtracking

## Approach
- **Sort** the string to group identical characters.
- **Initialize** a `used` boolean array and a `current` string to build permutations.
- **Base Case**: When the length of `current` reaches the string length, append to results.
- **Loop** through characters: skip if `used[i]` is true or if it's a duplicate of the previous character that wasn't used (`s[i] == s[i-1] && !used[i-1]`).
- **Recurse**: Mark as used, add to `current`, recurse, then backtrack.

## Edge Case
String with all identical characters or a single character.

## Complexity
Time: O(N! * N)
Space: O(N)

## Revision Note
Sort string -> loop characters -> skip used -> skip duplicates `s[i] == s[i-1] && !used[i-1]` -> add char -> recurse -> backtrack.
