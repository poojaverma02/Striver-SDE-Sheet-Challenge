# The Celebrity Problem

## Key Idea
Use a stack to repeatedly eliminate non-celebrities by comparing pairs of people. A celebrity knows no one, but everyone knows the celebrity.

## Pattern
Stack / Two Pointers

## Approach
- **Push all candidates**: Push all individuals from `0` to `N-1` onto the stack.
- **Eliminate**: While the stack has more than 1 person, pop two people (`A` and `B`). If `A` knows `B`, `A` cannot be a celebrity (push `B` back). Otherwise, `B` cannot be a celebrity (push `A` back).
- **Verify**: The last remaining person is a candidate. Verify by checking if the candidate knows no one and if everyone knows the candidate. If both hold true, return the candidate; otherwise, return `-1`.

## Edge Case
No celebrity exists in the group, or there is only one person.

## Complexity
Time: O(N)
Space: O(N) for the stack (can be optimized to O(1) using two pointers).

## Revision Note
Push all to stack -> pop two (`A`, `B`) -> if `M[A][B] == 1`, push `B`, else push `A` -> verify the last remaining candidate in O(N).
