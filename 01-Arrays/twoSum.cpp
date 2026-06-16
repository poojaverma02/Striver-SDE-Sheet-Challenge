// T.C: O(N) 
// S.C: O(N)
// Question Link: https://takeuforward.org/plus/dsa/problems/two-sum?source=strivers-sde-sheet

class Solution {
   public:
    // this question has 2 optimal Solution
    // 1. Sorting + Two Pointers : O(N) + O(NlogN)
    // 2. HashMap : O(N)
    vector<int> twoSum(vector<int>& nums, int target) {
        // using unordered_map becoz it will take O(1) time to insert
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            int required = target - nums[i];
            if (mp.find(required) != mp.end()) {
                return {mp[required], i};
            }
            mp[nums[i]] = i;
        }
        return {-1, -1};
    }
};

