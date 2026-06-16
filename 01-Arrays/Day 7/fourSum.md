# 4 Sum

## Key Idea
Use Sorting followed by two nested loops to fix the first two elements and apply the Two-Pointers approach for the remaining two elements to find quadruplets summing to `target`.

## Pattern
Sorting + Two Pointers

## Approach
- **Sort** the array.
- **Iterate** with `i` from `0` to `n-1`, skipping duplicates for `i`.
- **Iterate** with `j` from `i+1` to `n-1`, skipping duplicates for `j`.
- **Initialize** two pointers: `k = j + 1` and `l = n - 1`.
- **While** `k < l`, calculate the sum of the four elements.
  - If sum == target: add to answer, increment `k`, decrement `l`, and skip duplicates for both `k` and `l`.
  - If sum < target: increment `k`.
  - If sum > target: decrement `l`.

## Edge Case
Using `long long` for calculating `sum` prevents integer overflow when adding four potentially large integers.

## Complexity
Time: O(N^3)
Space: O(1) (excluding the space for the answer array)

## Revision Note
Sort first! Loop `i`, Loop `j`. Two pointers `k` and `l`. Remember to skip duplicates for all four variables!
