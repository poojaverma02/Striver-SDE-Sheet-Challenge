# Longest Subarray with Sum K

## Key Idea
Use Prefix Sum combined with a Hash Map. Keep track of the running sum and store the first occurrence index of each sum. If `sum - k` exists in the map, a subarray summing to `k` ends at the current index.

## Pattern
Prefix Sum + Hash Map

## Approach
- **Initialize** a map to store `prefix sum -> first index`.
- **Iterate** through the array, updating the running `sum`.
- If `sum == k`, update `maxLen` to `i + 1`.
- Calculate `rem = sum - k`. If `rem` exists in the map, a valid subarray is found from `preMap[rem] + 1` to `i`. Update `maxLen`.
- **Insert** the current `sum` into the map **only if** it doesn't already exist. This ensures we keep the longest possible subarray by maintaining the earliest index for each sum.

## Edge Case
Zeroes in the array (e.g., `[2, 0, 0, 3]`). By only storing the first occurrence of a sum, we correctly include trailing zeroes in the subarray.

## Complexity
Time: O(N * logN) if using `std::map`, or O(N) on average if using `std::unordered_map`.
Space: O(N) for storing the prefix sums in the map.

## Revision Note
Calculate `sum`. Check `sum - k` in map. Only add `sum` to map if NOT already present (to handle zeroes optimally).
