# Trapping Rainwater

## Key Idea
Use two pointers from both ends, maintaining the maximum height seen so far from left and right to compute trapped water on the go.

## Pattern
Two Pointers

## Approach
- **Initialize** `left` and `right` pointers, along with `leftMax` and `rightMax`.
- **Compare** `height[left]` and `height[right]` to decide which side to process.
- **Update** the respective max height or add to `total` water if the current height is less than the max.
- **Shift** the corresponding pointer inwards.

## Edge Case
Flat surface or constantly increasing/decreasing heights (no trapped water).

## Complexity
Time: O(N)
Space: O(1)

## Revision Note
Left and right pointers -> move the pointer with smaller height -> update respective max or add `max - height` to total.
