// T.C: O(N)
// S.C: O(1)
// Question Link: https://takeuforward.org/plus/dsa/problems/remove-duplicates-from-sorted-array?source=strivers-sde-sheet

class Solution {
   public:
    // Function to remove duplicates from the vector
    int removeDuplicates(vector<int>& nums) {
        // Initialize pointer for unique elements
        int i = 0;

        // Iterate through the vector
        for (int j = 1; j < nums.size(); j++) {
            /*If current element is different
            from the previous unique element*/
            if (nums[i] != nums[j]) {
                /* Move to the next position in
                the vector for the unique element*/
                i++;
                /* Update the current position
                with the unique element*/
                nums[i] = nums[j];
            }
        }

        // Return the number of unique elements
        return i + 1;
    }
};
