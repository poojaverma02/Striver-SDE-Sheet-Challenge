# Majority Element I

## Key Idea
Use Boyer-Moore Voting Algorithm. The majority element (appears > N/2 times) will always outlast other elements when opposite votes cancel each other out.

## Pattern
Boyer-Moore Voting Algorithm

## Approach
- **Initialize** a candidate `el` and a counter `cnt` to 0.
- **Iterate** through `nums`:
  - If `cnt == 0`, **set** `el = nums[i]` and `cnt = 1`.
  - Else if `nums[i] == el`, **increment** `cnt`.
  - Else **decrement** `cnt`.
- **Count** the occurrences of `el` in `nums` to verify if it is indeed a majority element (> N/2).

## Edge Case
No majority element exists (e.g., `[1, 2, 3]`). The verification phase handles this and returns `-1`.

## Complexity
Time: O(N)
Space: O(1)

## Revision Note
Boyer-Moore: cnt=0 -> candidate=num; same -> cnt++; diff -> cnt--. Verify count > N/2.
