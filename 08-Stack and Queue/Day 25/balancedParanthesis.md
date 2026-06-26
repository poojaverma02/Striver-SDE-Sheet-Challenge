# Balanced Parenthesis

## Key Idea
Use a stack to keep track of opening brackets and match them against incoming closing brackets to ensure valid pairing and correct nesting order.

## Pattern
Stack

## Approach
- **Traverse** the string character by character.
- **Push**: If the character is an opening bracket (`(`, `{`, `[`), push it onto the stack.
- **Pop & Match**: If it's a closing bracket, check if the stack is empty (invalid). Otherwise, pop the top of the stack and use `isMatched` to check if they form a valid pair.
- **Final Check**: After traversing, if the stack is empty, all brackets were matched; otherwise, the string is invalid.

## Edge Case
String starting with a closing bracket, or only containing opening brackets.

## Complexity
Time: O(N)
Space: O(N)

## Revision Note
Push open brackets -> on close bracket, check if stack empty -> pop top -> `isMatched(top, current)` -> finally return `st.empty()`.
