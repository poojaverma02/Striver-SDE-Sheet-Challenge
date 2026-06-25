// T.C: O(N) 
// S.C: O(N) 
// Question Link: https://takeuforward.org/plus/dsa/problems/balanced-paranthesis?source=strivers-sde-sheet

class Solution {
private:
    // Helper function to check if the opening and closing
    // brackets form a valid pair.
    bool isMatched(char open, char close) {
        if ((open == '(' && close == ')') ||
            (open == '{' && close == '}') ||
            (open == '[' && close == ']')) {
            return true;
        }
        return false;
    }

public:
    bool isValid(string str) {

        // Stack to store opening brackets
        stack<char> st;

        int n = str.length();

        // Traverse each character of the string
        for (int i = 0; i < n; i++) {

            // If the current character is an opening bracket,
            // push it onto the stack.
            if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
                st.push(str[i]);
            }
            else {

                // If we encounter a closing bracket but the stack
                // is empty, there is no matching opening bracket.
                if (st.empty())
                    return false;

                // Get the most recent opening bracket
                char ch = st.top();
                st.pop();

                // Check if the opening and closing brackets match.
                // If they don't, the string is invalid.
                if (!isMatched(ch, str[i])) {
                    return false;
                }
            }
        }

        // If the stack is empty, all brackets were matched.
        // Otherwise, there are unmatched opening brackets.
        return st.empty();
    }
};