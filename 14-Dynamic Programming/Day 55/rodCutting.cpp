// T.C: O(N*(rod length)
// S.C: O(rod length)
// Question Link: https://takeuforward.org/plus/dsa/problems/rod-cutting-problem?source=strivers-sde-sheet


class Solution {
public:
    // Function to solve the rod cutting problem
    int rodCutting(vector<int>& price, int n) {
        // Initialize DP table with dimensions [n + 1]
        vector<int> prev(n+1, 0), cur(n+1, 0);
        
        for(int length = 0; length <= n; length++){
            prev[length] = price[0]*length;
        }
        
        // Fill the DP table
        for (int ind = 1; ind < n; ++ind) { 
            for (int length = 1; length <= n; ++length) { 
                
                // Case when the piece is not taken
                int notTaken = 0+prev[length];
                
                // Case when the piece is taken
                int taken = INT_MIN;
                
                /* Length of the rod piece 
                corresponding to the current index*/
                int rodLength = ind + 1;
                
                // Check if the piece can be taken
                if (rodLength <= length) {
                    taken = price[ind] + cur[length - rodLength];
                }
                
                /* Update cur[length] with the maximum of 
                including or not including the current piece*/
                cur[length] = max(notTaken, taken);
            }
            prev = cur;
        }
        
        // Return the result 
        return prev[n];
    }
};