// T.C: O(2N), Traversing the array takes O(N) time, and traversing the stack will take overall O(N) time, as all the elements are pushed into the stack once.
// S.C: O(2N), The answer array takes O(N) space, and the space used by the stack will be O(N) in the worst case.
// Question Link: https://takeuforward.org/plus/dsa/problems/next-greater-element?source=strivers-sde-sheet

class Solution {
public:
    vector<int> nextLargerElement(vector<int> arr) {

        int n = arr.size();

        // Vector to store the Next Greater Element for each index
        vector<int> ans(n);

        // Stack to keep track of potential next greater elements
        stack<int> st;

        // Traverse the array from right to left
        for (int i = n - 1; i >= 0; i--) {

            // Current element
            int curEle = arr[i];

            // Remove all elements from the stack that are
            // smaller than or equal to the current element,
            // as they cannot be the Next Greater Element.
            while (!st.empty() && st.top() <= curEle) {
                st.pop();
            }

            // If the stack is empty, there is no greater element
            // on the right side.
            if (st.empty())
                ans[i] = -1;
            else
                // The top of the stack is the Next Greater Element.
                ans[i] = st.top();

            // Push the current element onto the stack so it can
            // act as the Next Greater Element for elements to its left.
            st.push(curEle);
        }

        // Return the resulting array
        return ans;
    }
};