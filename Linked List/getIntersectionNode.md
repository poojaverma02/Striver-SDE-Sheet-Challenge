# Intersection of Two Linked Lists

## Key Idea
Traverse both linked lists using two pointers. When a pointer reaches the end of its list, redirect it to the head of the *other* list. By doing this, both pointers will traverse exactly `length(A) + length(B)` nodes, guaranteeing they will meet at the intersection node or both reach `NULL` simultaneously if there is no intersection.

## Pattern
Two Pointers

## Approach
- **Initialize** two pointers `d1 = headA` and `d2 = headB`.
- **Loop** while `d1 != d2`.
- Inside the loop, if `d1` reaches `NULL`, reassign it to `headB`. Otherwise, move to `d1->next`.
- If `d2` reaches `NULL`, reassign it to `headA`. Otherwise, move to `d2->next`.
- When the loop terminates, `d1` and `d2` will be pointing to the intersection node (or `NULL` if they don't intersect).
- **Return** `d1`.

## Edge Case
- One or both lists are `NULL`. The code handles this at the very beginning and immediately returns `NULL`.
- No intersection. The pointers will both reach the ends of their second traversed lists simultaneously (`d1 == NULL` and `d2 == NULL`), breaking the loop and correctly returning `NULL`.

## Complexity
Time: O(N + M) where N and M are the lengths of the two lists.
Space: O(1) using only two pointers.

## Revision Note
Two pointers! When `p1` hits NULL, move to `headB`. When `p2` hits NULL, move to `headA`. They sync up and meet at the intersection.
