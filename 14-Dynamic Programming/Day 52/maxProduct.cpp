// T.C: O(N)
// S.C: O(1)
// Question Link: https://takeuforward.org/plus/dsa/problems/maximum-product-subarray-in-an-array?source=strivers-sde-sheet


class Solution {
public:
    /* Function to find the product of
    elements in maximum product subarray */
	int maxProduct(vector<int>& nums) {
	    int n = nums.size();
	    
	    int ans = INT_MIN; // to store the answer
	    
	    // Indices to store the prefix and suffix multiplication
        int prefix = 1, suffix = 1;
        
        // Iterate on the elements of the given array
        for(int i=0; i < n; i++) {
            
            /* Resetting the prefix and suffix
            multiplication if they turn out to be zero */
            if(prefix == 0) prefix = 1;
            if(suffix == 0) suffix = 1;
            
            // update the prefix and suffix multiplication
            prefix *= nums[i];
            suffix *= nums[n-i-1];
            
            // store the maximum as the answer
            ans = max(ans, max(prefix, suffix));
        }
        
        // return the result
        return ans;
	}
};
