# Trie - Advanced Operations

## Key Idea
Extending the standard Trie to support frequency counts: `cntEndWith` (tracks how many words end at a node) and `cntPrefix` (tracks how many words pass through / start with the prefix up to a node). This allows counting exact words, counting prefix occurrences, and erasing words safely.

## Pattern
Trie Data Structure / Prefix & Word Frequency Counting

## Approach
- **Node Structure**:
  - `Node* links[26]` array.
  - `int cntEndWith = 0` and `int cntPrefix = 0`.
  - Methods: `increaseEnd()`, `increasePrefix()`, `deleteEnd()`, `reducePrefix()`.
- **Insert(word)**: For each character, navigate/create node, then call `node->increasePrefix()`. At the end of the word, call `node->increaseEnd()`.
- **CountWordsEqualTo(word)**: Navigate through `word`. If path breaks, return 0. At the end node, return `node->cntEndWith`.
- **CountWordsStartingWith(prefix)**: Navigate through `prefix`. If path breaks, return 0. At the end of prefix, return `node->cntPrefix`.
- **Erase(word)**: First verify `countWordsEqualTo(word) > 0`. Traverse `word`, calling `reducePrefix()` at each step, and `deleteEnd()` at the final node.

## Edge Case
Erasing a word that doesn't exist (check existence first). Multiple identical words inserted.

## Complexity
Time: O(L) for all operations (`insert`, `countWordsEqualTo`, `countWordsStartingWith`, `erase`) where $L$ is word length.
Space: O(N \times L \times 26) for Trie nodes.

## Revision Note
Advanced Trie replaces boolean `flag` with `cntEndWith` and `cntPrefix`. `insert` increments `cntPrefix` at each node and `cntEndWith` at end. `erase` decrements them.
