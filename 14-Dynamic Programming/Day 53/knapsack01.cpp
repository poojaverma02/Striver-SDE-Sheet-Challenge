// T.C: O(N*W)
// S.C: O(W)
// Question Link: https://takeuforward.org/plus/dsa/problems/0-and-1-knapsack?source=strivers-sde-sheet


class Solution{
public:  
    // Function to solve the 0/1 Knapsack problem
    int knapsack01(vector<int>& wt, vector<int>& val, int n, int W) {
        /* Initialize a vector 'prev' to represent 
        the previous row of the DP table*/
        vector<int> prev(W + 1, 0);

        /* Base condition: Fill in 'prev' 
        for the weight of the first item*/
        for (int i = wt[0]; i <= W; i++) {
            prev[i] = val[0];
        }

        // Fill in the table using a bottom-up approach
        for (int ind = 1; ind < n; ind++) {
            for (int cap = W; cap >= 0; cap--) {
                
                /* Calculate the maximum value by either
                excluding the current item or including it*/
                int notTaken = prev[cap];
                int taken = INT_MIN;

                /* Check if the current item can be included
                without exceeding the knapsack's capacity*/
                if (wt[ind] <= cap) {
                    taken = val[ind] + prev[cap - wt[ind]];
                }

                // Update 'prev' for the current capacity
                prev[cap] = max(notTaken, taken);
            }
        }

        /* The final result is in the 
        last cell of the 'prev' vector*/
        return prev[W];
    }
};