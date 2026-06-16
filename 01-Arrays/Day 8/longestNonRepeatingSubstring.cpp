// T.C: O(N) 
// S.C: O(256), Hash array to store all the characters.
// Question Link: https://takeuforward.org/plus/dsa/problems/longest-substring-without-repeating-characters?source=strivers-sde-sheet

class Solution {
   public:
    int longestNonRepeatingSubstring(string& s) {
        int n = s.size();
        
        // 256 to cover all ASCII characters
        int alphabets = 256;
        
        // hash array to store the LAST SEEN index of each character
        // initialized to -1 meaning "never seen"
        int hash[alphabets];
        for (int i = 0; i < alphabets; i++) {
            hash[i] = -1;
        }
        
        // l = left pointer, r = right pointer of sliding window
        int l = 0, r = 0, maxLen = 0;
        
        while (r < n) {
            
            // if character was seen before and is inside current window
            if (hash[s[r]] != -1) {
                
                // shrink window from left to just after last occurrence
                // max() ensures l never moves backward
                // (character could be seen before current window started)
                l = max(hash[s[r]] + 1, l);
            }
            
            // calculate current window length and update maxLen
            int len = r - l + 1;
            maxLen = max(len, maxLen);
            
            // update last seen index of current character
            hash[s[r]] = r;
            
            // expand window from right
            r++;
        }
        
        return maxLen;
    }
};

