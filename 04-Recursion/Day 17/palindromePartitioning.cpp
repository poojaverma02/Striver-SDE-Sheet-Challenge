// T.C: O(N × 2^N), where N is the length of string given.
// This is because we generate all possible partitions (exponential) and each palindrome check can take up to O(N).
// S.C:  O(N), because the auxiliary space used (recursion stack + path) is O(N).
// Question Link: https://takeuforward.org/plus/dsa/problems/palindrome-partitioning?source=strivers-sde-sheet

class Solution {
   private:
    void dfs(int index, string s, vector<string> &path,
             vector<vector<string>> &res) {
        // If the index reaches the end of the string
        if (index == s.size()) {
            // Add the current partition to the result
            res.push_back(path);
            return;
        }
        // Iterate over the substring starting from 'index'
        for (int i = index; i < s.size(); ++i) {
            // Check if the substring s[index..i] is a palindrome
            if (isPalindrome(s, index, i)) {
                // If true, add it to the current path
                path.push_back(s.substr(index, i - index + 1));
                // Recur for the remaining substring
                dfs(i + 1, s, path, res);
                // Backtrack: remove the last added substring
                path.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int start, int end) {
        // Check if the substring s[start..end] is a palindrome
        while (start <= end) {
            // If characters do not match, it's not a palindrome
            if (s[start++] != s[end--]) return false;
        }
        return true;  // Otherwise, it's a palindrome
    }

   public:
    vector<vector<string>> partition(string s) {
        // Resultant vector to store all partitions
        vector<vector<string>> res;
        // Temporary vector to store current partition
        vector<string> path;
        // Start the depth-first search from index 0
        dfs(0, s, path, res);
        return res;
    }
};

