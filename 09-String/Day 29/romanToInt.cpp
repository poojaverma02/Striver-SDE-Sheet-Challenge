// T.C: O(n)
// S.C: O(1)
// Question Link: https://takeuforward.org/plus/dsa/problems/roman-to-integer?source=strivers-sde-sheet

class Solution {
public:
    int romanToInt(string s) {
        // Map each Roman numeral character to its integer value
        unordered_map<char, int> mp = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int total = 0;

        for (int i = 0; i < s.size(); i++) {
            // Subtractive case: current symbol is less than the next one
            // e.g. IV → subtract 1 (I) then add 5 (V) = 4
            //      IX → subtract 1, add 10 = 9
            //      XL → subtract 10, add 50 = 40
            if (i + 1 < s.size() && mp[s[i]] < mp[s[i + 1]]) {
                total -= mp[s[i]];
            } else {
                // Additive case: current symbol is >= next, just add it
                total += mp[s[i]];
            }
        }

        return total;
    }
};