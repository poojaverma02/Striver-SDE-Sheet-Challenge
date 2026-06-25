// T.C: O(N^2) 
// S.C: O(N) 
// Question Link: https://takeuforward.org/plus/dsa/problems/sort-a-stack?source=strivers-sde-sheet

class Solution {
private:
    // Inserts an element into its correct position
    // in a stack that is already sorted.
    void insertSorted(stack<int>& st, int element) {

        // If the stack is empty or the current top
        // is greater than or equal to the element,
        // push the element.
        if (st.empty() || st.top() <= element) {
            st.push(element);
            return;
        }

        // Store the top element
        int topElement = st.top();
        st.pop();

        // Recursively find the correct position
        insertSorted(st, element);

        // Put the removed element back
        st.push(topElement);
    }

public:
    void sortStack(stack<int>& st) {

        // Base case
        if (st.empty())
            return;

        // Remove the top element
        int topElement = st.top();
        st.pop();

        // Recursively sort the remaining stack
        sortStack(st);

        // Insert the removed element
        // into its correct position
        insertSorted(st, topElement);
    }
};
