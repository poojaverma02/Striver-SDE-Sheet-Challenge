// T.C: O(N) or O(NxlogN) depending on the map data structure used
// S.C: O(N) for the map to store the prefix xors and their indices
// Question Link: https://takeuforward.org/plus/dsa/problems/count-subarrays-with-given-xor-k?source=strivers-sde-sheet

class Solution{
public:
    int subarraysWithXorK(vector<int> &nums, int k) {
        int n = nums.size();
        
        // stores running XOR of elements from index 0 to i
        int xr = 0;
        
        // map to store frequency of each prefix XOR seen so far
        map<int, int> mpp;
        
        // base case: empty prefix has XOR = 0, seen once
        // handles subarrays starting from index 0
        mpp[xr]++;
        
        int cnt = 0;
        
        for(int i = 0; i < n; i++){
            
            // update prefix XOR by including current element
            xr = xr ^ nums[i];
            
            // if prefix_xor[i] ^ x = k
            // then x = prefix_xor[i] ^ k
            // x is the prefix XOR we need to have seen before
            int x = xr ^ k;
            
            // all previous indices where prefix XOR == x
            // form a valid subarray with XOR = k ending at i
            cnt += mpp[x];
            
            // record current prefix XOR in map
            mpp[xr]++;
        }
        
        return cnt;
    }
};