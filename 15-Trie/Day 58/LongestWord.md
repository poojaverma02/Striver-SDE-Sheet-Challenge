# Longest Word With All Prefixes

## Key Idea
Given an array of strings, we need to find the longest string such that every prefix of that string is also present in the array. If there is a tie in length, we pick the lexicographically smaller string. We can solve this efficiently by inserting all words into a Trie and checking if every node along a word's path in the Trie has `flag = true` (marking the end of a complete word).

## Pattern
Trie Data Structure / Prefix Checking

## Approach
- **Insert Words**: Build a Trie and insert all words from `nums` into it.
- **Check Prefixes**: For each word in `nums`, traverse its path in the Trie:
  - At every character node along the path, check `node->isEnd()`.
  - If any node along the path is *not* marked as the end of a word (`!isEnd()`), then at least one prefix of the word is missing. Return `false`.
  - If all nodes are marked as end of words, return `true`.
- **Update Result**: Maintain a `longest` string initialized to `""`.
  - If a word passes the prefix check and `word.size() > longest.size()`, update `longest = word`.
  - If `word.size() == longest.size()` and `word < longest` (lexicographically smaller), update `longest = word`.
- **Return**: Return `longest` if non-empty, otherwise `"None"`.

## Edge Case
No word has all prefixes present (returns `"None"`). Multiple words of max length with all prefixes present (picks lexicographically smallest).

## Complexity
Time: O(N \times M) where $N$ is the number of words and $M$ is the maximum length of a word.
Space: O(N \times M \times 26) for the Trie data structure.

## Revision Note
Insert all words into Trie. For each word, verify `isEnd() == true` for every prefix node along its Trie path. Keep track of the longest word, tie-breaking with lexicographical comparison (`<`). Return `"None"` if no word satisfies condition.
