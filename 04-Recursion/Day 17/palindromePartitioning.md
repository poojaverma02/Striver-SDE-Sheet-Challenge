# Palindrome Partitioning

## Key Idea
Use depth-first search (backtracking) to generate all possible partitions, branching out whenever a valid palindrome substring is found.

## Pattern
Recursion / Backtracking

## Approach
- **Iterate** over possible end indices for the current substring starting from `index`.
- **Check** if the substring `s[index..i]` is a palindrome.
- **Recurse**: If it is a palindrome, add it to the current path and recursively call the function for the remaining substring `i + 1`.
- **Backtrack**: Remove the last added palindrome from the path to explore other partitions.
- **Base Case**: If `index` reaches the end of the string, add the path to the results.

## Edge Case
String with all identical characters or string of length 1.

## Complexity
Time: O(N × 2^N)
Space: O(N)

## Revision Note
Loop `i` from `index` to end -> check `isPalindrome` -> add to path -> recurse `dfs(i+1)` -> pop from path.
