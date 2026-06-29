// T.C:  O(3N) ~ O(N)
// The input string is reversed firstly, taking O(n) time.
// The string is then traversed taking another O(n) time.
// Every word encountered in the string is again reversed taking overall O(n) time.
// S.C: O(1)
// Question Link: https://takeuforward.org/plus/dsa/problems/reverse-every-word-in-a-string?source=strivers-sde-sheet

class Solution {
   private:
    // Reverses characters in s[start..end] in-place
    void reverseString(string &s, int start, int end) {
        while (start < end) {
            swap(s[start++], s[end--]);
        }
    }

   public:
    string reverseWords(string s) {
        int n = s.length();

        // Step 1: Reverse the entire string
        // "the sky is blue" → "eulb si yks eht"
        reverseString(s, 0, n - 1);

        // i = write pointer (next position to place cleaned char)
        // j = read pointer (scans through the reversed string)
        int i = 0, j = 0, start = 0, end = 0;

        while (j < n) {
            // Skip leading/inter-word spaces
            while (j < n && s[j] == ' ') j++;
            if (j == n) break;

            // Step 2: Copy next word into position i (compacting in-place)
            start = i;
            while (j < n && s[j] != ' ') {
                s[i++] = s[j++];
            }
            end = i - 1;

            // Step 3: Reverse the word we just wrote to restore correct order
            // e.g. "eulb" → "blue"
            reverseString(s, start, end);

            // Add exactly one space after each word (except the last)
            if (j < n) {
                s[i++] = ' ';
            }
        }

        // Trim any trailing space (can occur if original ended with spaces)
        if (i > 0 && s[i - 1] == ' ') i--;

        // Return only the valid portion of the in-place modified string
        return s.substr(0, i);
    }
};
