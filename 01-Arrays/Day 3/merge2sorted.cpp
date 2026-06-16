//T.C: O(N + M)
//S.C: O(1) 
//Link: https://takeuforward.org/plus/dsa/problems/merge-two-sorted-arrays-without-extra-space?source=strivers-sde-sheet

class Solution {
   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1;
        int ind = n + m - 1;

        while (j >= 0) {
            if (i >= 0 && nums1[i] >= nums2[j]) {
                nums1[ind] = nums1[i];

                ind--, i--;
            }

            else {
                nums1[ind] = nums2[j];

                ind--, j--;
            }
        }

        return;
    }
};