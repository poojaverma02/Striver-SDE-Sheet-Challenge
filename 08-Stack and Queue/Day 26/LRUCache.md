# LRU Cache

## Key Idea
Use a hash map and a doubly linked list to achieve $O(1)$ time complexity for both `get` and `put` operations. The linked list maintains the usage order, while the hash map provides direct access to the nodes.

## Pattern
Design / Hash Map + Doubly Linked List

## Approach
- **Data Structures**: Maintain a map `mpp` mapping keys to `Node` pointers. Use dummy `head` and `tail` nodes for the doubly linked list.
- **Get Operation**: If the key exists, fetch its node, extract the value, move the node to the front (right after `head`) to mark it as most recently used, and return the value.
- **Put Operation**: 
  - If the key exists, update its value and move it to the front.
  - If the key doesn't exist and the cache is full (capacity reached), remove the least recently used node (`tail->prev`) from both the list and the map.
  - Insert the new node at the front of the list and add it to the map.

## Edge Case
Cache with capacity 1. Accessing a key that doesn't exist returns `-1`.

## Complexity
Time: O(1) for `get` and `put`.
Space: O(Capacity)

## Revision Note
DLL with dummy head/tail + unordered_map -> `get`: move node to front (`insertAfterHead`) -> `put`: if exists, update & move front. If full, delete `tail->prev`.
