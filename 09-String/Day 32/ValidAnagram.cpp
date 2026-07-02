// T.C: O(N)
// S.C: O(1)
// Question Link: https://takeuforward.org/plus/dsa/problems/valid-anagram?source=strivers-sde-sheet

class Solution {	
public:
    bool anagramStrings(string& s, string t) {
        // Different lengths can never be anagrams
        if (s.length() != t.length()) return false;

        // Frequency counter for 26 lowercase letters
        vector<int> count(26, 0);

        // Increment counts for each char in s
        for (char c : s) count[c - 'a']++;

        // Decrement counts for each char in t
        for (char c : t) count[c - 'a']--;

        // If s and t are anagrams, every count should net to 0
        for (int i : count) {
            if (i != 0) return false;
        }
        return true;
    }
};