// T.C: O(M)
// S.C: O(K)
// Question Link: https://takeuforward.org/plus/dsa/problems/rabin-karp-algorithm?source=strivers-sde-sheet

class Solution {
public:
    // Function to find the starting index of all occurrences of pattern in text
    vector<int> search(string pat, string txt) {
        int n = pat.length();
        int m = txt.length();
        
        // Primes for Rabin karp algorithm
        int p = 7, mod = 101;
        
        // To store the hash values of pattern and susbtring of text
        int hashPat = 0, hashText = 0;
        
        int pRight = 1, pLeft = 1;
        
        // Computing the initial hash values
        for(int i=0; i < n; i++) {
            hashPat += ((pat[i]-'a'+1) * pRight) % mod;
            hashText += ((txt[i]-'a'+1) * pRight) % mod;
            pRight = (pRight * p) % mod;
        }
        
        // List to store the result
        vector<int> ans;
        
        // Traverse the text string
        for(int i=0; i <= m-n; i++) {
            
            // If the hash value matches
            if(hashPat == hashText) {
                // Add the index of the result if the substring matches
                if(txt.substr(i, n) == pat) ans.push_back(i);
            }
            
            // Updating the hash values
            hashText = (hashText - ((txt[i] - 'a'+1) * pLeft) % mod + mod) % mod;
            hashText = (hashText + ((txt[i+n] - 'a'+1) * pRight) % mod) % mod;
            hashPat = (hashPat * p) % mod;
            
            // Updating the prime multiples
            pLeft = (pLeft * p) % mod;
            pRight = (pRight * p) % mod;
        }
        
        return ans; // Return the stored result
    } 
};