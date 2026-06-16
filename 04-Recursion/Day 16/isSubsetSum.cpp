// T.C: O(n × target)
// S.C: O(target)
// Question Link: https://takeuforward.org/plus/dsa/problems/subset-sum-equals-to-target?source=strivers-sde-sheet


class Solution {
public:
    bool isSubsetSum(vector<int> arr, int target) {
        int n = arr.size();

        // dp[t] = true if a subset with sum 't' can be formed
        // using elements processed so far.
        vector<bool> dp(target + 1, false);

        // Base case: a sum of 0 is always achievable (empty subset).
        dp[0] = true;

        // Process each number in the array one at a time.
        for (int i = 0; i < n; i++) {
            // Traverse sums from high to low.
            // This ensures each element is used at most once per subset
            // (since we don't want to reuse an already-updated dp[t] in
            // the same iteration, which would be like having infinite copies).
            for (int t = target; t >= arr[i]; t--) {
                if (dp[t - arr[i]]) {
                    dp[t] = true;
                }
            }
        }

        return dp[target];
    }
};