# Check if Linked List is Palindrome

## Key Idea
Find the middle of the linked list, reverse the second half, and compare it with the first half element by element.

## Pattern
Fast & Slow Pointers / In-place Reversal

## Approach
- **Find** the middle of the linked list using slow and fast pointers.
- **Reverse** the second half of the list starting from `slow->next`.
- **Compare** the nodes of the first half and the reversed second half.
- **Restore** the original list by reversing the second half again.

## Edge Case
List with 0 or 1 node is always a palindrome.

## Complexity
Time: O(2N)
Space: O(1)

## Revision Note
Find mid with slow/fast -> reverse from mid->next -> compare halves -> reverse again to restore -> return true/false.
