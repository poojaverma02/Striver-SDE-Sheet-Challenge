// T.C: O(N) or O(NxlogN) depending on the map data structure used
// S.C: O(N) for the map to store the prefix sums and their indices
// Question Link: https://takeuforward.org/plus/dsa/problems/longest-subarray-with-sum-k?source=strivers-sde-sheet

class Solution {
   public:
    //+ve & -ve use PrefixSum + HashMap
    // Only +ve then use 2 pointer or sliding window
    int longestSubarray(vector<int> &nums, int k) {
        int n = nums.size();

        map<int, int> preMap;
        int sum = 0;
        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (sum == k) {
                maxLen = max(maxLen, i + 1);
            }

            int rem = sum - k;
            //(sum - k) was seen before
            if (preMap.find(rem) != preMap.end()) {
                int len = i - preMap[rem];
                maxLen = max(maxLen, len);
            }
            // Edge Case: [2,0,0,3] if k=3 then longest [0,0,3]
            //  update the map if sum is not already present
            if (preMap.find(sum) == preMap.end()) {
                preMap[sum] = i;  // only first occurrence
            }
        }
        return maxLen;
    }
};
