// T.C: O(N)
// S.C: O(K)
// Question Link: https://takeuforward.org/plus/dsa/problems/distinct-numbers-in-each-subarray?source=strivers-sde-sheet

class Solution {
public:
    // Method to find the number of distinct elements in each sliding window of size k
    vector<int> distinctNumbers(vector<int>& nums, int k) {
        int n = nums.size();  // Get the size of the input vector
        unordered_map<int, int> freq;  // Map to store the frequency of elements in the current window
        vector<int> result;  // Vector to store the result of distinct elements count for each window

        // Initialize the first window by counting frequencies of elements in the first k elements
        for (int i = 0; i < k; ++i)
            freq[nums[i]]++;  // Increment the frequency of each element in the window

        // Add the distinct element count of the first window to the result
        result.push_back((int)freq.size());

        // Slide the window across the array
        for (int i = k; i < n; ++i) {
            // Remove the element that is going out of the window
            int outgoing = nums[i - k];  // Element leaving the window
            freq[outgoing]--;  // Decrease its frequency
            if (freq[outgoing] == 0)  // If the frequency becomes 0, remove it from the map
                freq.erase(outgoing);

            // Add the new element that is entering the window
            int incoming = nums[i];  // Element entering the window
            freq[incoming]++;  // Increment its frequency

            // Add the distinct element count of the current window to the result
            result.push_back((int)freq.size());
        }

        // Return the result containing the distinct element counts for each window
        return result;
    }
};