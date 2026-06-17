// T.C: O(n²)
// S.C: O(n)
// Question Link: https://takeuforward.org/plus/dsa/problems/permutation-sequence?source=strivers-sde-sheet

class Solution {
   public:
    // Function to get the k-th permutation sequence of numbers 1..n
    string getPermutation(int n, int k) {
        // Initialize a list of numbers from 1 to n
        vector<int> nums;
        for (int i = 1; i <= n; i++) nums.push_back(i);

        // Compute factorials up to n
        vector<int> fact(n, 1);
        for (int i = 1; i < n; i++) fact[i] = fact[i - 1] * i;

        // Decrement k to convert to 0-based index
        k--;

        string ans = "";

        // Build the permutation one position at a time
        for (int i = n - 1; i >= 0; i--) {
            // Determine which number should be at current position
            int index = k / fact[i];
            ans += to_string(nums[index]);

            // Remove used number from list
            nums.erase(nums.begin() + index);

            // Update k for next position
            k %= fact[i];
        }

        return ans;
    }
};
