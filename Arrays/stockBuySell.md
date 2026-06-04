# Best Time to Buy and Sell Stock

## Key Idea
Keep track of the minimum price seen so far. For every element, calculate the profit if sold today and update the maximum profit.

## Pattern
Array Manipulation (Greedy)

## Approach
- **Initialize** `minPrice` to `INT_MAX` and `maxPro` to `0`.
- **Iterate** over each price in the array.
- **Update** `minPrice` if the current price is lower.
- **Calculate** profit by subtracting `minPrice` from the current price, and **update** `maxPro`.

## Edge Case
Strictly descending prices. `maxPro` remains `0` as profit is never positive.

## Complexity
Time: O(N)
Space: O(1)

## Revision Note
Track `minPrice` from left -> Update `maxPro = max(maxPro, current - minPrice)`.
