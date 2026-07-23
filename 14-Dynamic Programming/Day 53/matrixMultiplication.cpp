// T.C: O(N^3)
// S.C: O(N^2)
// Question Link: https://takeuforward.org/plus/dsa/problems/matrix-chain-multiplication?source=strivers-sde-sheet


class Solution {
public:
    int matrixMultiplication(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        // A single matrix needs no multiplication cost
        for (int i = 1; i < n; ++i) {
            dp[i][i] = 0;
        }

        // Filling the dp array
        for (int length = 2; length < n; ++length) { // length of the chain
            for (int i = 1; i <= n - length; ++i) {
                int j = i + length - 1;
                for (int k = i; k < j; ++k) {
                    int cost = dp[i][k] + dp[k + 1][j] + nums[i - 1] * nums[k] * nums[j];
                    if (cost < dp[i][j]) {
                        dp[i][j] = cost;
                    }
                }
            }
        }

        // The result is in dp[1][n-1]
        return dp[1][n - 1];
    }
};