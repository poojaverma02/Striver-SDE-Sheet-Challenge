// T.C: O(N*M)
// S.C: O(M)
// Question Link: https://takeuforward.org/plus/dsa/problems/longest-common-subsequence?source=strivers-sde-sheet

class Solution{
public:
    /* Function to calculate the length
    of the Longest Common Subsequence*/
    int lcs(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        
        /* Initialize two vectors to store the
        current and previous rows of the DP table*/
        vector<int> prev(m + 1, 0), cur(m + 1, 0);

        /* Base case is covered as we have initialized
        the prev and cur vectors to 0.*/

        for (int ind1 = 1; ind1 <= n; ind1++) {
            for (int ind2 = 1; ind2 <= m; ind2++) {
                
                // Characters match, increment LCS length
                if (str1[ind1 - 1] == str2[ind2 - 1])
                    cur[ind2] = 1 + prev[ind2 - 1]; 
                else
                    cur[ind2] = max(prev[ind2], cur[ind2 - 1]);
            }
            // Update the previous row with current row
            prev = cur; 
        }
        // Return the length of Longest Common Subsequence
        return prev[m]; 
    }
};