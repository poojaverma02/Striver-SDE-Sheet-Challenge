# Fractional Knapsack

## Key Idea
Sort the items by their value-to-weight ratio in descending order and greedily pick items until the knapsack is full, taking a fraction if an item doesn't fully fit.

## Pattern
Greedy Algorithm / Sorting

## Approach
- **Compute** the value-to-weight ratio for each item.
- **Sort** the items based on this ratio in descending order.
- **Iterate** through the sorted items:
  - If the item's weight is less than or equal to the remaining capacity, add its full value.
  - If it exceeds, take a fraction that perfectly fills the remaining capacity and break.

## Edge Case
Capacity exactly matches some combination, or capacity is zero.

## Complexity
Time: O(N log N)
Space: O(N)

## Revision Note
Calculate `val/wt` -> sort descending -> take full if `wt <= cap`, else take fraction `val * (cap/wt)` -> break.
