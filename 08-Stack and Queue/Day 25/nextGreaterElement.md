# Next Greater Element

## Key Idea
Traverse the array from right to left while maintaining a monotonic decreasing stack to efficiently find the next greater element for each index.

## Pattern
Monotonic Stack

## Approach
- **Initialize** an answer array and an empty stack.
- **Traverse Backward**: Start from the end of the array to the beginning.
- **Maintain Stack**: For each element `curEle`, pop all elements from the stack that are `<= curEle` (since they cannot be the next greater element for any element to the left).
- **Determine Answer**: If the stack is empty, the answer is `-1`. Otherwise, the top of the stack is the next greater element.
- **Push**: Push `curEle` onto the stack for elements to the left.

## Edge Case
Array is sorted in descending order (all answers `-1`).

## Complexity
Time: O(2N)
Space: O(2N)

## Revision Note
Loop right to left -> `while(!st.empty() && st.top() <= curEle) st.pop()` -> if empty, `ans[i] = -1` else `ans[i] = st.top()` -> `st.push(curEle)`.
