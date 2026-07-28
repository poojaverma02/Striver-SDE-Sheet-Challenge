# Trie Implementation and Operations

## Key Idea
A Trie (Prefix Tree) is a tree-like data structure used to efficiently store and retrieve keys in a dataset of strings. Nodes store references to child nodes (alphabet size 26) and a boolean flag indicating if a node marks the end of a complete word.

## Pattern
Trie Data Structure / Prefix Tree

## Approach
- **Node Structure**:
  - `Node* links[26]` initialized to `nullptr`.
  - `bool flag` indicating end of word.
  - Methods: `containsKey(ch)`, `put(ch, node)`, `get(ch)`, `setEnd()`, `isEnd()`.
- **Insert(word)**: Traverse nodes according to characters in `word`. If a link doesn't exist, create a new `Node`. Mark `flag = true` at the final node.
- **Search(word)**: Traverse nodes according to characters. If any character link is missing, return `false`. Return `node->isEnd()` at the final node.
- **StartsWith(prefix)**: Traverse nodes according to characters in `prefix`. If all characters exist, return `true`.

## Edge Case
Empty string insert/search. Search for prefix that is not a complete word.

## Complexity
Time:
- Insertion: O(L) where $L$ is word length.
- Search: O(L).
- Prefix Search: O(L).
Space: O(N \times L \times 26) in the worst case for storing characters.

## Revision Note
Trie Node has `links[26]` and `flag`. Insert creates missing nodes and sets `flag=true` at end. Search verifies path and `flag=true`. StartsWith only verifies path.
