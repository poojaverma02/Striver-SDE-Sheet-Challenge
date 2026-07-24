// T.C: O(N*Target)
// S.C: O(Target)
// Question Link: https://takeuforward.org/plus/dsa/problems/coin-change-ii?source=strivers-sde-sheet

class Solution{
public:
    int MOD = 1e9 + 7;

    /* Function to count the number of 
    ways to make change for the target sum*/
    int count(vector<int>& coins, int N, int amount) {
        // Initialize a vector to store previous DP state
        vector<long long> prev(amount + 1, 0);  

        // Initialize base condition
        for (int i = 0; i <= amount; i++) {
            /* There is one way to make change
            for multiples of the first coin*/
            if (i % coins[0] == 0)
                prev[i] = 1;  
            /* Else condition is automatically fulfilled,
            as the prev vector is initialized to zero*/
        }

        for (int ind = 1; ind < N; ind++) {
            // Initialized a vector to store current DP state
            vector<long long> cur(amount + 1, 0);  
            for (int target = 0; target <= amount; target++) {
                
                // Number of ways without taking current coin
                int notTaken = prev[target];  

                int taken = 0;
                if (coins[ind] <= target)
                    // Number of ways by taking current coin
                    taken = cur[target - coins[ind]];  
                
                // Total number of ways for current target
                cur[target] = (notTaken + taken) % MOD;  
            }
            /* Update the previous DP state with 
            the current state for the next coin*/
            prev = cur;  
        }
        /* Return the total number of ways
        to make change for the target*/
        return prev[amount];  
    }
};
