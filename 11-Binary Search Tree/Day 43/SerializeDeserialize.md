# Serialize and Deserialize Binary Tree

## Key Idea
Serialization is the process of converting a tree into a string format so that it can be stored or transmitted. Deserialization reconstructs the tree from that string. A Level-Order (BFS) traversal handles this intuitively.

## Pattern
Tree Traversal / BFS / Serialization

## Approach
- **Serialize**:
  - Use a queue for BFS.
  - If a node is `NULL`, append `"#,"` to the string.
  - Otherwise, append its value followed by a comma `","`.
  - Push its left and right children into the queue (even if they are `NULL`).
- **Deserialize**:
  - Parse the comma-separated string.
  - Read the first value and create the root.
  - Use a queue initialized with the root.
  - While the queue is not empty, pop a node. Read the next two values from the string.
  - If the left value is not `"#""`, create a left child, link it, and push it to the queue.
  - If the right value is not `"#""`, create a right child, link it, and push it to the queue.

## Edge Case
Empty tree (serialize to empty string).

## Complexity
Time: O(N) where N is the number of nodes in the tree.
Space: O(N) for the BFS queue and the output string.

## Revision Note
Serialize: BFS queue -> push nulls as `"#"` -> separate by `,`.
Deserialize: Stringstream -> `getline(s, str, ',')` -> BFS queue -> link left and right children based on parsed tokens.
