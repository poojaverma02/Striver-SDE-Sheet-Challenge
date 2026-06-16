# Longest Substring Without Repeating Characters

## Key Idea
Use a Sliding Window (Two Pointers) approach along with a hash array to store the last seen indices of characters to avoid duplicate characters within the window.

## Pattern
Sliding Window + Hash Array

## Approach
- **Initialize** an array `hash` of size 256 with `-1` to store the last seen index of each ASCII character.
- **Initialize** `l = 0`, `r = 0` and `maxLen = 0`.
- **Iterate** using the right pointer `r` through the string.
- If the current character `s[r]` is seen before (`hash[s[r]] != -1`), move the left pointer `l` to `hash[s[r]] + 1`. Use `max()` to ensure `l` only moves forward (handles cases where the previously seen duplicate is outside the current window).
- **Calculate** the current window length `r - l + 1` and update `maxLen`.
- **Update** the `hash` for `s[r]` with the current index `r`.
- **Increment** `r` to expand the window.

## Edge Case
A duplicate character found before the current `l` pointer should not pull `l` backward. The `max(hash[s[r]] + 1, l)` handles this safely.

## Complexity
Time: O(N) since both `l` and `r` pointers traverse the string at most once.
Space: O(256) ≈ O(1) for the hash array.

## Revision Note
Keep track of the `last_seen` index of characters. If seen, `l = max(last_seen + 1, l)`. Update `last_seen = r`.
