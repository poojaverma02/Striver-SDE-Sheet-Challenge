// T.C:  O(N) 
// S.C: O(N)
// Question Link: https://takeuforward.org/plus/dsa/problems/maximum-of-minimums-for-every-window-size?source=strivers-sde-sheet


class Solution {
public:
    // Function to compute the maximum of minimum values for all window sizes
    vector<int> maxOfMin(vector<int> &arr) {

        // Store the length of the array
        int n = arr.size();

        // 'left[i]'  = index of previous smaller element
        // 'right[i]' = index of next smaller element
        vector<int> left(n), right(n);

        // ------------------------------------------------------
        // Step 1: Compute previous smaller elements using a stack
        // ------------------------------------------------------
        stack<int> st;

        for (int i = 0; i < n; ++i) {

            // Pop until we find a strictly smaller element
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            // If stack empty: no smaller on left, otherwise top is the index
            left[i] = st.empty() ? -1 : st.top();

            // Push current index
            st.push(i);
        }

        // ------------------------------------------------------
        // Step 2: Compute next smaller elements using stack
        // ------------------------------------------------------
        while (!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; --i) {

            // Pop until we find a strictly smaller element
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            // If empty → no smaller on right → use n
            right[i] = st.empty() ? n : st.top();

            // Push current index
            st.push(i);
        }

        // ------------------------------------------------------
        // Step 3: ans[len] = maximum among minimums for window length "len"
        // ------------------------------------------------------
        vector<int> ans(n + 1, INT_MIN);

        for (int i = 0; i < n; ++i) {

            // Length where element arr[i] is the minimum
            int len = right[i] - left[i] - 1;

            // Update the best minimum for this window length
            ans[len] = max(ans[len], arr[i]);
        }

        // ------------------------------------------------------
        // Step 4: Fill remaining values so smaller windows have
        // at least the values of larger windows
        // ------------------------------------------------------
        for (int len = n - 1; len >= 1; --len) {
            ans[len] = max(ans[len], ans[len + 1]);
        }

        // ------------------------------------------------------
        // Step 5: Retrieve results for window size 1..n
        // ------------------------------------------------------
        vector<int> res(n);
        for (int i = 1; i <= n; ++i) {
            res[i - 1] = ans[i];
        }

        return res;
    }
};