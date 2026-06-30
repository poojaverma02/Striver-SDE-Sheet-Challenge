// T.C: O(n)
// S.C: O(1)
// Question Link: https://takeuforward.org/plus/dsa/problems/string-to-integer-atoi?source=strivers-sde-sheet

class Solution {
public:
    int myAtoi(string input) {
        int i = 0;
        int n = input.size();

        // Step 1: Skip leading whitespace characters
        while (i < n && input[i] == ' ') {
            i++;
        }

        // Step 2: Check for an optional '+' or '-' sign
        int sign = 1;
        if (i < n && input[i] == '-') {
            sign = -1;
            i++;
        } else if (i < n && input[i] == '+') {
            i++;
        }

        // Step 3: Convert digits to a number, using long long to avoid 
        // overflow issues while we check bounds
        long long result = 0;
        while (i < n && isdigit(input[i])) {
            result = result * 10 + (input[i] - '0');
            i++;

            // Step 4: Clamp to INT_MAX if the signed result overflows positive range
            if (result * sign >= INT_MAX) {
                return INT_MAX;
            }
            // Step 5: Clamp to INT_MIN if the signed result overflows negative range
            if (result * sign <= INT_MIN) {
                return INT_MIN;
            }
        }

        // Step 6: Apply the sign and return the final integer
        return result * sign;
    }
};
