// T.C: O(N * M * log N)
// Comparing two strings during sort costs up to O(M) (character-by-character comparison).
// Sorting does O(N*logN) comparisons.
// S.C: O(M), as the ans variable can store the length of the prefix which in the worst case will be O(M).
// Question Link: https://takeuforward.org/plus/dsa/problems/longest-common-prefix?source=strivers-sde-sheet

class Solution {	
public:
    string longestCommonPrefix(vector<string>& str) {
        // Edge case: empty input vector has no common prefix
        if (str.empty()) return "";

        string ans = "";
        int n = str.size();

        // Sort lexicographically. After sorting, the first and last strings
        // will differ the most among all strings (they are the two "extremes"),
        // so comparing just these two is enough to find the common prefix
        // for the entire array.
        sort(str.begin(), str.end());

        string first = str[0];      // Lexicographically smallest string
        string last = str[n - 1];   // Lexicographically largest string

        // The common prefix can't be longer than the shorter of the two strings
        int minLen = min(first.length(), last.length());

        // Compare characters of first and last one by one
        for (int i = 0; i < minLen; i++) {
            if (first[i] != last[i]) {
                // Mismatch found, stop and return prefix found so far
                return ans;
            }
            // Characters match, add to the answer
            ans += first[i];
        }

        // If loop completes, the entire shorter string is the common prefix
        return ans;
    }
};