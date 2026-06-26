# Next Smaller Element

## Key Idea
Traverse the array from right to left while maintaining a monotonic increasing stack to efficiently find the next smaller element for each index.

## Pattern
Monotonic Stack

## Approach
- **Initialize** an answer array and an empty stack.
- **Traverse Backward**: Loop from the end of the array down to index 0.
- **Maintain Stack**: For the current element `curEle`, pop elements from the stack as long as they are `>= curEle`. This removes elements that can no longer serve as the next smaller element for anything to the left.
- **Determine Answer**: If the stack becomes empty, there is no smaller element on the right (`-1`). Otherwise, the stack's top is the next smaller element.
- **Push**: Push `curEle` onto the stack.

## Edge Case
Array is sorted in ascending order (all elements will have `-1` as the next smaller element).

## Complexity
Time: O(2N)
Space: O(2N)

## Revision Note
Loop right to left -> `while(!st.empty() && st.top() >= curEle) st.pop()` -> if empty, `ans[i] = -1` else `ans[i] = st.top()` -> `st.push(curEle)`.
