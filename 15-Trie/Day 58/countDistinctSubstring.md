# Number of Distinct Substrings in a String

## Key Idea
Every distinct substring of a string corresponds to a unique path in a Trie starting from the root node. By inserting all suffixes of the string into a Trie, each newly created Trie node represents a newly discovered distinct substring. The total count of nodes created (plus 1 for the empty string) equals the total number of distinct substrings.

## Pattern
Trie Data Structure / Substring Counting

## Approach
- **Trie Structure**: Standard `Node` with `links[26]` array.
- **Nested Iteration**:
  - Outer loop `i` from $0$ to $N-1$ (starting position of substring).
  - Reset `node = root`.
  - Inner loop `j` from `i` to $N-1$ (ending position of substring).
  - Check if `node->containsKey(s[j])`.
  - If false, a new distinct substring is found: increment counter `c++` and create a new `Node` via `node->put(s[j], new Node())`.
  - Move `node = node->get(s[j])`.
- **Memory Cleanup**: Implement a recursive helper `deleteTrie` to free all allocated Trie nodes.
- **Return**: Return `c + 1` to include the empty string in the total count of distinct substrings.

## Edge Case
Empty string (returns 1). String with all identical characters e.g. `"aaaa"` (returns $N + 1$).

## Complexity
Time: O(N^2) as we iterate through all $O(N^2)$ substrings, doing $O(1)$ operations per character using Trie pointers.
Space: O(N^2) in the worst case for storing up to $O(N^2)$ nodes in the Trie.

## Revision Note
Insert all suffixes `s[i..N-1]` into a Trie. Every time a new Trie node is created, increment `count++`. Return `count + 1` (accounting for the empty string).
