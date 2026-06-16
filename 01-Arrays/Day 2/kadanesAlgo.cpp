// T.C: O(N)
// S.C: O(1)
// Question Link: https://takeuforward.org/plus/dsa/problems/kadane's-algorithm?source=strivers-sde-sheet

class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (sum > maxi) {
                maxi = sum;
            }
            //-ve elements only hamper our output
            if (sum < 0) {
                sum = 0;
            }
        }
        return maxi;
    }
};