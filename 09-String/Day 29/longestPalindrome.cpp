// T.C: O(n²), where n is the length of the string. For each character, we expand around it for both odd and even length palindromes, which takes O(n) for each center.
// S.C: O(1)
// Question Link: https://takeuforward.org/plus/dsa/problems/longest-palindromic-substring?source=strivers-sde-sheet

class Solution {
private:
    // Expands outward from (left, right) as long as characters match.
    // For odd-length palindromes: call with left == right (single center).
    // For even-length palindromes: call with right == left + 1 (two-char center).
    // Returns the [start, end] indices of the longest palindrome found.
    pair<int, int> expandAroundCenter(string &s, int left, int right) {
        while (left >= 0 && right < (int)s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        // Loop overshoots by 1 on each side before breaking, so pull back
        return {left + 1, right - 1};
    }

public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";

        int start = 0, end = 0; // tracks best palindrome window found so far

        for (int i = 0; i < n; i++) {
            // Case 1: odd-length palindrome centered at i
            // e.g. "racecar" → center at 'e'
            auto odd = expandAroundCenter(s, i, i);

            // Case 2: even-length palindrome centered between i and i+1
            // e.g. "abba" → center between the two b's
            auto even = expandAroundCenter(s, i, i + 1);

            // Update best if this odd-center palindrome is longer
            if (odd.second - odd.first > end - start) {
                start = odd.first;
                end = odd.second;
            }

            // Update best if this even-center palindrome is longer
            if (even.second - even.first > end - start) {
                start = even.first;
                end = even.second;
            }
        }

        return s.substr(start, end - start + 1);
    }
};