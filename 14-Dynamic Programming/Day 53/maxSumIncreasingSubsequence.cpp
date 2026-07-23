// T.C: O(n²)
// S.C: O(n)
// Question Link: https://takeuforward.org/plus/dsa/problems/maximum-sum-increasing-subsequence?source=strivers-sde-sheet

class Solution {
public:
    // Main function using tabulation
    int maxSumIncreasingSubsequence(vector<int>& arr, int n) {
        // Initialize DP array, dp[i] stores max sum ending at i
        vector<int> dp(n);
        // Initialize each dp[i] with arr[i] itself
        for (int i = 0; i < n; i++) dp[i] = arr[i];

        // Iterate through all elements
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                // If strictly increasing, update dp[i]
                if (arr[i] > arr[j]) dp[i] = max(dp[i], dp[j] + arr[i]);
            }
        }

        // Answer is max in dp array
        return *max_element(dp.begin(), dp.end());
    }
};


