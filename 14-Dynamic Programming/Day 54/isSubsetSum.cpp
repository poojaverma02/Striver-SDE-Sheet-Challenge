// T.C: O(N*Target)
// S.C: O(Target)
// Question Link: https://takeuforward.org/plus/dsa/problems/subset-sum-equals-to-target?source=strivers-sde-sheet

class Solution{
private:
    /* Function to check if there is a subset
    of 'arr' with a sum equal to 'target'*/
    bool func(int n, int target, vector<int> &arr) {
        /* Initialize a vector 'prev' to store
        the previous row of the DP table*/
        vector<bool> prev(target + 1, false);

        /* Base case: If the target sum is 0, we
        can always achieve it by taking no elements*/
        prev[0] = true;

        /* Base case: If the first element of 'arr' is less
        than or equal to 'target', set prev[arr[0]] to true*/
        if (arr[0] <= target) {
            prev[arr[0]] = true;
        }

        /* Iterate through the elements 
        of 'arr' and update the DP table*/
        for (int ind = 1; ind < n; ind++) {
            /* Initialize a new row 'cur' to store
            the current state of the DP table*/
            vector<bool> cur(target + 1, false);

            /* Base case: If the target sum is 0,
            we can achieve it by taking no elements*/
            cur[0] = true;

            for (int i = 1; i <= target; i++) {
                /* If we don't take the current element, the
                result is the same as the previous row*/
                bool notTaken = prev[i];

                /* If we take the current element, subtract its 
                value from the target and check the previous row*/
                bool taken = false;
                if (arr[ind] <= i) {
                    taken = prev[i - arr[ind]];
                }

                /* Store the result in the current DP 
                table row for the current subproblem*/
                cur[i] = notTaken || taken;
            }

            /* Update 'prev' with the curren
            t row 'cur' for the next iteration*/
            prev = cur;
        }

        // The final result is stored in prev[target]
        return prev[target];
    }
public:
    /* Function to check if there is a subset
    of 'arr' with a sum equal to 'target'*/
    int isSubsetSum(vector<int> &arr, int target){
        //Return the result
        return func(arr.size(), target, arr);
    }
};