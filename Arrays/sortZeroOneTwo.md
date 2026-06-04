# Sort an Array of 0's, 1's, and 2's

## Key Idea
Use three pointers to partition the array into three regions: 0s on the left, 1s in the middle, and 2s on the right.

## Pattern
Dutch National Flag Algorithm (Three Pointers)

## Approach
- **Initialize** `low = 0`, `mid = 0`, and `high = n - 1`.
- **If** `nums[mid] == 0`, **swap** with `nums[low]` and **increment** both `low` and `mid`.
- **If** `nums[mid] == 1`, just **increment** `mid`.
- **If** `nums[mid] == 2`, **swap** with `nums[high]` and **decrement** `high`.

## Edge Case
Array with only one type of element (e.g., all 1s). The `mid` pointer naturally sweeps through in O(N).

## Complexity
Time: O(N)
Space: O(1)

## Revision Note
`0` -> swap low, mid++. `1` -> mid++. `2` -> swap mid, high--.
