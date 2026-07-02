// T.C: O(N) * O(average length of string) 
// S.C: O(N) + O(average length of string)
// Question Link: https://takeuforward.org/plus/dsa/problems/count-and-say?source=strivers-sde-sheet


class Solution {
public:
    string countAndSay(int n) {
        // Base case: the sequence starts at "1"
        if (n == 1) return "1";

        // Recursively get the previous term in the sequence
        string prev = countAndSay(n - 1);

        int len = prev.length();
        string ans = "";
        int count = 1; // tracks run-length of the current repeating char

        // Walk through prev, comparing each char to the one before it
        for (int i = 1; i < len; i++) {
            if (prev[i] == prev[i - 1]) {
                count++; // same char as before, extend the run
            } else {
                // run broke — record "count + char" for the finished run
                ans.push_back('0' + count);
                ans.push_back(prev[i - 1]);
                count = 1; // reset for the new run
            }
        }

        // The loop never records the last run (it exits right after it),
        // so flush it here
        ans.push_back('0' + count);
        ans.push_back(prev[len - 1]);

        return ans;
    }
};