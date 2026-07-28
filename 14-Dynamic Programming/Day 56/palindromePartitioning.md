# Palindrome Partitioning

## Key Idea
To partition a string such that every substring in the partition is a palindrome, we can use Backtracking (DFS). At each step, we check if the substring starting from `index` to `i` is a palindrome. If it is, we add it to the path and recurse for `i + 1`.

## Pattern
Backtracking / DFS / String Partitioning

## Approach
- **DFS Function**: `dfs(index, s, path, res)`
  - **Base Case**: If `index == s.size()`, push `path` into `res` and return.
  - **Loop**: Iterate `i` from `index` to `s.size() - 1`.
  - **Palindrome Check**: If `s[index..i]` is a palindrome:
    - Add `s.substr(index, i - index + 1)` to `path`.
    - Recurse `dfs(i + 1, s, path, res)`.
    - Backtrack: pop the last string from `path`.
- **Palindrome Helper**: Two pointers checking `s[start++] == s[end--]`.

## Edge Case
Single-character string. String with all unique characters.

## Complexity
Time: O(N \times 2^N) where $2^N$ is the max number of partitions and $O(N)$ for checking palindromes/substring creation.
Space: O(N) for recursion stack and path array.

## Revision Note
Backtracking. For each start `index`, loop `i` to end. If `s[index..i]` is palindrome, add substring to `path`, recurse `dfs(i+1)`, and backtrack `path.pop_back()`.
