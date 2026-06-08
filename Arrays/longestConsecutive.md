# Longest Consecutive Sequence

## Key Idea
Store all array elements in a Hash Set to allow O(1) lookups. Iterate through the set and only start counting the sequence length when we find a number that is the beginning of a sequence (i.e., `num - 1` is not in the set).

## Pattern
Hashing (Hash Set)

## Approach
- **Initialize** an `unordered_set` and insert all elements from the array.
- **Iterate** over each element in the set.
- **Check** if the current element is the start of a sequence by verifying that `num - 1` does not exist in the set.
- If it is the start, continuously check for `num + 1`, `num + 2`, etc., in the set, and increment the sequence count.
- **Update** the `longest` sequence length found so far.

## Edge Case
Empty array. Handle immediately by returning `0`.

## Complexity
Time: O(3N) — O(N) to insert elements, and O(2N) overall to find consecutive sequences since each element is part of a sequence iteration at most twice.
Space: O(N) for the unordered_set.

## Revision Note
Put everything in a set. Only build sequences if `x - 1` is missing. Count upwards using `x + 1`.
