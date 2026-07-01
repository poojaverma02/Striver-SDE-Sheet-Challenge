// T.C: O(N)
// S.C: O(N)
// Question Link: https://takeuforward.org/plus/dsa/problems/z-function?source=strivers-sde-sheet

class Solution {
private:
    // Compute the Z array for the combined string
    vector<int> computeZarray(string s) {
        int n = s.size(); // size of string
    
        vector<int> Z(n, 0); // Z-array
        
        // Pointers to mark the window
        int left = 0, right = 0;
        
        // For every character
        for(int i=1; i < n; i++) {
            
            // Out of window
            if(i > right) {
                while(i + Z[i] < n && s[i+Z[i]] == s[Z[i]])
                    Z[i]++;
            }
            
            // Else (Inside the window)
            else {
                // Check for inside
                if(i + Z[i - left] <= right) Z[i] = Z[i - left];
                
                // Else compute again using brute force method
                else { 
                    Z[i] = right - i + 1; // Take the answer till boundary
                    
                    // Start matching beyond boundary using brute force
                    while(i + Z[i] < n && s[i + Z[i]] == s[Z[i]]) Z[i]++;
                }
            }
            
            // Update the window only if it extends beyond current boundary
            if (i + Z[i] - 1 > right) {
                left = i;
                right = i + Z[i] - 1;
            }
        }
        
        return Z; // Return the computed Z-array
    }
    
public:
    // Function to find all indices of pattern in text
    vector<int> search(string text, string pattern)   {
        string s = pattern + '$' + text; // Combined string
        
        // Function call to find the Z array for the combined string
        vector<int> Z = computeZarray(s);
        
        // Length of pattern and text
        int n = text.size(), m = pattern.size();
        
        // To store the result
        vector<int> ans;
        
        // Iterate on the combined string after the delimiter
        for(int i = m+1; i < s.size(); i++) {
            if(Z[i] == m) ans.push_back(i - (m + 1));
        }
        
        return ans;
    }
};
