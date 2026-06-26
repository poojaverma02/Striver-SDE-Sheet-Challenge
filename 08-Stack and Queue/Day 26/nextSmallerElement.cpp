// T.C: O(2N), Traversing the array takes O(N) time, and traversing the stack will take overall O(N) time, as all the elements are pushed into the stack once.
// S.C: O(2N), The answer array takes O(N) space, and the space used by the stack will be O(N) in the worst case.
// Question Link: https://takeuforward.org/plus/dsa/problems/next-smaller-element?source=strivers-sde-sheet


class Solution {
public:
    vector<int> nextSmallerElements(const vector<int>& arr) {
        int n = arr.size();

        // Stores the Next Smaller Element for each index
        vector<int> ans(n);

        // Monotonic increasing stack (stores element values)
        stack<int> st;

        // Traverse the array from right to left
        for (int i = n - 1; i >= 0; i--) {

            int curEle = arr[i];

            // Remove all elements that are greater than or equal to
            // the current element since they cannot be the next smaller
            while (!st.empty() && st.top() >= curEle) {
                st.pop();
            }

            // If the stack is empty, there is no smaller element on the right
            if (st.empty())
                ans[i] = -1;
            else
                // The top of the stack is the next smaller element
                ans[i] = st.top();

            // Push the current element so it can act as the
            // next smaller element for elements on its left
            st.push(curEle);
        }

        return ans;
    }
};