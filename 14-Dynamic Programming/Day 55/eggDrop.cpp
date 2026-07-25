// T.C: O(n * log k)
// S.C: O(n)
// Question Link: https://takeuforward.org/plus/dsa/problems/super-egg-drop?source=strivers-sde-sheet


class Solution {
public:
    // Function to find minimum attempts needed with n eggs and k floors
    int eggDrop(int n, int k) {
        // 1D array to store maximum floors that can be checked with i eggs
        vector<int> dp(n + 1, 0);

        // Initialize number of moves
        int moves = 0;

        // Loop until we can check at least k floors
        while (dp[n] < k) {
            moves++;
            // Update dp array from n to 1
            for (int i = n; i >= 1; i--) {
                dp[i] = dp[i] + dp[i - 1] + 1;
            }
        }

        return moves;
    }
};
