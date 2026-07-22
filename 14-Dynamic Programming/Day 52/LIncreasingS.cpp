// T.C: O(N*logN)
// S.C: O(N)
// Question Link: https://takeuforward.org/plus/dsa/problems/longest-increasing-subsequence?source=strivers-sde-sheet

// Dp solution is giving TLE for large inputs, so we will use binary search to find the index of the current element in the temporary array and replace it with the current element. This way we can maintain the increasing order of the subsequence and also keep track of the length of the longest increasing subsequence.

class Solution {
public:
    /* Function to find the longest increasing 
    subsequence in the given array */
    int LIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> temp;
        temp.push_back(nums[0]);
        
        // Iterate on the elements of the array
        for(int i=1; i < n; i++) {
            
            // If the current element can be added to the subsequence
            if(nums[i] > temp.back()) 
                temp.push_back(nums[i]); 
                
            // Otherwise
            else {
                // Index at which the current element must be placed
                int ind = lower_bound(temp.begin(), temp.end(), nums[i]) -
                          temp.begin();
                          
                // Place the current element in the subsequence
                temp[ind] = nums[i];
            }    
            
        }
        
        // Return the length of temporary subsequence created so far
        return temp.size();
    }    
};


