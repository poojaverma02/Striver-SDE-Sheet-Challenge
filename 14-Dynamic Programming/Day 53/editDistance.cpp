// T.C: O(N*M)
// S.C: O(M)
// Question Link: https://takeuforward.org/plus/dsa/problems/edit-distance?source=strivers-sde-sheet

class Solution {
public:
    /* Function to calculate the minimum number of operations 
       required to transform string start into string target */
    int editDistance(string start, string target) {
        int n = start.size();  // Length of the start string
        int m = target.size(); // Length of the target string

        /* Declare two arrays to store the previous and current rows of edit distances */
        vector<int> prev(m + 1, 0); // Previous row (initialized to 0)
        vector<int> cur(m + 1, 0);  // Current row (initialized to 0)

        // Initialize the first row (base case: transforming "" to target[0..m])
        for (int j = 0; j <= m; j++) {
            prev[j] = j;  // It takes j operations to transform "" to target[0..j]
        }

        // Calculate edit distances row by row
        for (int i = 1; i <= n; i++) {
            // Initialize the first column of current row (base case: transforming start[0..i] to "")
            cur[0] = i;  // It takes i operations to transform start[0..i] to ""
            
            for (int j = 1; j <= m; j++) {
                // If characters match, no additional cost
                if (start[i - 1] == target[j - 1]) {
                    cur[j] = prev[j - 1];
                } 
                else {
                    // Take minimum of three choices (Insert, Delete, Substitute)
                    cur[j] = 1 + min(prev[j - 1], min(prev[j], cur[j - 1]));
                }
            }

            // After processing the current row, swap prev and cur to avoid overwriting
            swap(prev, cur);  // prev now contains the current row, and cur is reset
        }

        // The value at prev[m] contains the final edit distance
        return prev[m];  // prev now contains the last row after the swap
    }
};

