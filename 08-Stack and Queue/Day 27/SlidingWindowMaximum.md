# Sliding Window Maximum

## Key Idea
Use a Deque (Double-ended queue) to store indices, maintaining a monotonically decreasing order of values, so the front always holds the maximum of the current window.

## Pattern
Deque / Monotonic Queue

## Approach
- **Initialize** a deque to store indices.
- **Traverse**: For each element at index `i`:
- **Remove Out of Bounds**: Remove indices from the front of the deque that are outside the current window `(<= i - k)`.
- **Maintain Monotonicity**: Remove indices from the back of the deque if their corresponding values are less than or equal to the current element `arr[i]`.
- **Push**: Add the current index `i` to the back.
- **Record Max**: If `i >= k - 1`, the front of the deque is the maximum for the window, so add `arr[dq.front()]` to the answer.

## Edge Case
Window size `K` equals 1, or `K` equals array size.

## Complexity
Time: O(N)
Space: O(K)

## Revision Note
Deque stores indices -> remove front if `<= i - k` -> remove back while `arr[back] <= arr[i]` -> push `i` -> add `arr[front]` to answer if `i >= k-1`.
