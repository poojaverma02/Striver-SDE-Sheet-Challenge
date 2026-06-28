# LFU Cache

## Key Idea
Use a hash map to map frequencies to doubly linked lists (to handle LRU tie-breaking) and another hash map to map keys to nodes, enabling $O(1)$ operations for an LFU cache.

## Pattern
Design / Hash Map + Doubly Linked List

## Approach
- **Data Structures**: `keyNode` map stores keys to `Node` pointers. `freqListMap` stores frequencies to `List` pointers (a custom Doubly Linked List).
- **Update Frequency**: On `get` or `put` (if exists), remove the node from its current frequency list, increment its frequency count, and add it to the front of the next higher frequency list. Update `minFreq` if the old frequency was the minimum and its list became empty.
- **Eviction**: When capacity is reached during `put`, find the list corresponding to `minFreq`, remove the node at its tail (Least Recently Used among LFU), erase it from `keyNode`, and then insert the new node with frequency 1.

## Edge Case
Cache with 0 capacity.

## Complexity
Time: O(1) for `get` and `put`.
Space: O(Capacity)

## Revision Note
`freqListMap` + `keyNode` map. Custom DLL for each frequency -> on access, `updateFreqListMap()`: move node to `freq+1` list, update `minFreq` if needed -> on evict, delete `tail->prev` from `freqListMap[minFreq]`.
