# Two Sum

## Key Idea
Use a Hash Map to store the elements and their indices as we iterate. For each element, check if the required complementary value (`target - current_element`) exists in the map.

## Pattern
Hashing / Hash Map

## Approach
- **Initialize** an `unordered_map` to store `element -> index`.
- **Iterate** over the array.
- **Calculate** the `required` value by subtracting the current element from `target`.
- **Check** if the `required` value exists in the map.
  - If it exists, return the indices of the `required` value and the current element.
  - If it does not exist, insert the current element and its index into the map.

## Edge Case
If no valid pair exists, the function should correctly handle returning a default fallback (e.g., `{-1, -1}`).

## Complexity
Time: O(N)
Space: O(N)

## Revision Note
Optimal using HashMap. Iterate and look up `target - nums[i]`. If not found, add `nums[i]` to the map. O(N) time and O(N) space.
