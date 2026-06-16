// T.C: O(amount × n)
// S.C: O(amount)
// Question Link: https://takeuforward.org/plus/dsa/problems/minimum-coins?source=strivers-sde-sheet

class Solution {
    //Greedy approach will not work here as it may not give the optimal solution. So we will use dynamic programming to solve this problem.
   public:
    int MinimumCoins(vector<int>& coins, int amount) {
        // dp[i] will store the minimum number of coins needed to make amount
        // 'i'. Initialize all values to INT_MAX, representing "not yet
        // reachable / impossible".
        vector<int> dp(amount + 1, INT_MAX);

        // Base case: 0 coins are needed to make an amount of 0.
        dp[0] = 0;

        // Build up the solution for every amount from 1 to the target amount.
        for (int i = 1; i <= amount; i++) {
            // Try using each available coin denomination to form amount 'i'.
            for (int coin : coins) {
                // Only consider this coin if:
                // 1. It's not larger than the current amount 'i' (coin <= i)
                // 2. The remaining amount (i - coin) is actually reachable
                //    (dp[i - coin] != INT_MAX means we found a valid way to
                //    make it)
                if (coin <= i && dp[i - coin] != INT_MAX) {
                    // Update dp[i] if using this coin gives a smaller coin
                    // count than what we've found so far for amount 'i'. dp[i -
                    // coin] + 1 means: take the best solution for the smaller
                    // amount, then add 1 for the current coin used.
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        // If dp[amount] is still INT_MAX, it means the amount could not be
        // formed using any combination of the given coins -> return -1.
        // Otherwise, return the minimum number of coins found.
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};