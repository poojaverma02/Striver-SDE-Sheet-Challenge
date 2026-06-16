# Add Two Numbers

## Key Idea
Traverse both linked lists simultaneously, adding the values of the nodes along with any carry from the previous addition. Create new nodes for the sum digits and attach them to a new result list.

## Pattern
Dummy Node + Carry Arithmetic

## Approach
- **Initialize** a `dummy` node to simplify the head of the new list, and a `temp` pointer.
- **Initialize** `carry = 0`.
- **Loop** while `l1 != NULL`, `l2 != NULL`, or `carry != 0`.
- Calculate `sum = (l1 ? l1->data : 0) + (l2 ? l2->data : 0) + carry`.
- Update `carry = sum / 10`.
- Create a new node with `sum % 10` and attach it to `temp->next`.
- Move `temp`, `l1`, and `l2` forward.
- **Return** `dummy->next`.

## Edge Case
- Unequal lengths of `l1` and `l2`. We treat `NULL` as `0`.
- A carry remaining after both lists are exhausted (e.g., `9 + 9 = 18`, so a new node `1` must be added at the end).

## Complexity
Time: O(max(M, N)) where M and N are lengths of the lists.
Space: O(max(M, N)) to store the newly created result linked list.

## Revision Note
Dummy node. Loop until `l1`, `l2`, AND `carry` are all empty. Handle `NULL` nodes as value `0`.
