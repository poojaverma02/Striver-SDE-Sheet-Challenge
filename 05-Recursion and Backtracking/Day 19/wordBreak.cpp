// T.C: O(n × L)
// S.C: O(n)
// Question Link: https://takeuforward.org/plus/dsa/problems/word-break?source=strivers-sde-sheet

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // Convert the dictionary to a set for O(1) average-time
        // lookups instead of scanning the vector each time.
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size();

        // dp[i] = true means the prefix s[0..i) (first i characters)
        // can be fully segmented into dictionary words.
        vector<bool> dp(n + 1, false);

        // Base case: the empty prefix (0 characters) is trivially
        // "segmented" already — this lets the first real word match
        // starting at index 0 get marked as reachable.
        dp[0] = true;

        // Find the length of the longest word in the dictionary, so
        // the inner loop below never wastes time checking substring
        // lengths that couldn't possibly match any dictionary word.
        int maxLen = 0;
        for (auto &w : wordDict) maxLen = max(maxLen, (int)w.size());

        // Walk through every starting position i in the string.
        for (int i = 0; i < n; i++) {
            // If this position isn't reachable (no valid segmentation
            // gets us here), there's no point trying to extend from
            // it, so skip ahead.
            if (!dp[i]) continue;

            // From position i, try every possible word length, from
            // 1 up to maxLen (capped so we don't go past the end of
            // the string).
            for (int len = 1; len <= maxLen && i + len <= n; len++) {
                // Check if the substring s[i, i+len) is a valid
                // dictionary word.
                if (dict.count(s.substr(i, len))) {
                    // If so, the prefix ending at i+len is now
                    // reachable too — mark it.
                    dp[i + len] = true;
                }
            }
        }

        // dp[n] tells us whether the entire string (prefix of full
        // length n) can be segmented into dictionary words.
        return dp[n];
    }
};