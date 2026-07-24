// T.C: O(N*M)
// S.C: O(M)
// Question Link: https://takeuforward.org/plus/dsa/problems/minimum-falling-path-sum?source=strivers-sde-sheet

class Solution {
public:
    /* Function to find the minimum 
    path sum in the given matrix */
    int minFallingPathSum(vector<vector<int>> &matrix) {
        int n = matrix.size(); 
        int m = matrix[0].size(); 
        
        // Represents previous row's minimum path sums
        vector<int> prev(m, 0); 
        
        // Represents current row's minimum path sums
        vector<int> cur(m, 0);  

        // Initialize the first row (base condition)
        for (int j = 0; j < m; j++) {
            prev[j] = matrix[0][j];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                /* Calculate the minimum path sum for the 
                current cell considering three possible 
                directions: up, left diagonal, and right diagonal*/

                // Up direction
                int up = matrix[i][j] + prev[j];

                // Left diagonal direction
                int leftDiagonal = matrix[i][j];
                if (j - 1 >= 0) {
                    leftDiagonal += prev[j - 1];
                } else {
                    leftDiagonal += 1e9; 
                }

                // Right diagonal direction (if it's a valid move)
                int rightDiagonal = matrix[i][j];
                if (j + 1 < m) {
                    rightDiagonal += prev[j + 1];
                } else {
                    rightDiagonal += 1e9; 
                }

                /* Store the minimum of the
                three paths in the current row*/
                cur[j] = min(up, min(leftDiagonal, rightDiagonal));
            }

            /* Update the 'prev' array with the values 
            from the 'cur' array for the next iteration*/
            prev = cur;
        }

        /* Find the minimum value in the last row of 'prev',
        which represents minimum path sums ending at each cell*/
        int mini = INT_MAX;
        for (int j = 0; j < m; j++) {
            mini = min(mini, prev[j]);
        }

        /* The minimum path sum is the minimum
        value in the last row of 'prev'*/
        return mini;
    }
};


