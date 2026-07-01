// T.C: O(N*N)
// S.C: O(N)
// Question Link: https://takeuforward.org/plus/dsa/problems/minimum-insertions-to-make-string-palindrome?source=strivers-sde-sheet

class Solution{
private:
    /* Function to calculate the length 
    of the Longest Common Subsequence*/
    int lcs(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        /* Create two arrays to store the 
        previous and current rows of DP values*/
        vector<int> prev(m + 1, 0), cur(m + 1, 0);

        /* Base Case is covered as we have
        initialized the prev and cur to 0.*/

        for (int ind1 = 1; ind1 <= n; ind1++) {
            for (int ind2 = 1; ind2 <= m; ind2++) {
                if (s1[ind1 - 1] == s2[ind2 - 1])
                    cur[ind2] = 1 + prev[ind2 - 1];
                else
                    cur[ind2] = max(prev[ind2], cur[ind2 - 1]);
            }
            // Update the prev array with current values
            prev = cur;
        }
        // The value at prev[m] contains length of LCS
        return prev[m];
    }

    /* Function to calculate the length of 
    the Longest Palindromic Subsequence*/
    int longestPalindromeSubsequence(string s) {
        string t = s;
        reverse(s.begin(), s.end());
        return lcs(s, t);
    }
public:
    /* Function to calculate the minimum insertions
    required to make a string palindrome*/
    int minInsertion(string s) {
        int n = s.size();
        int k = longestPalindromeSubsequence(s);

        /* The minimum insertions required is the 
        difference between the string length and 
        its longest palindromic subsequence length*/
        return n - k;
    }
};
