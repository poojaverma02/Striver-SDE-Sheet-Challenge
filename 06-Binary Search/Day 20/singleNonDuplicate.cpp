// T.C: O(logN)
// S.C: O(1)
// Question Link: https://takeuforward.org/plus/dsa/problems/single-element-in-sorted-array?source=strivers-sde-sheet

class Solution {
public:
    int singleNonDuplicate(vector<int> &nums) {
        int n = nums.size();

        // Edge case: only one element, it must be the unique one
        if (n == 1) return nums[0];

        // Edge case: if the first element doesn't match its neighbor,
        // it's the unique element (since pairs are normally adjacent)
        if (nums[0] != nums[1]) return nums[0];

        // Edge case: if the last element doesn't match its neighbor,
        // it's the unique element
        if (nums[n - 1] != nums[n - 2]) return nums[n - 1];

        // Binary search over the "inner" range, excluding the first
        // and last elements (already handled above)
        int low = 1, high = n - 2;

        while (low <= high) {
            int mid = (low + high) / 2;

            // If nums[mid] doesn't match either neighbor, it's the unique element
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
                return nums[mid];
            }

            // Determine which side of mid the "correctly paired" elements are on.
            //
            // Before the unique element, pairs are aligned as:
            //   (even index, odd index) -> nums[even] == nums[even+1]
            // After the unique element, pairs shift to:
            //   (odd index, even index) -> nums[odd] == nums[odd+1] becomes nums[even] == nums[even-1]
            //
            // So:
            // - If mid is odd and matches the element to its LEFT (mid-1),
            //   the pairing pattern is still "normal" -> unique element is to the right
            // - If mid is even and matches the element to its RIGHT (mid+1),
            //   the pairing pattern is still "normal" -> unique element is to the right
            if ((mid % 2 == 1 && nums[mid] == nums[mid - 1]) ||
                (mid % 2 == 0 && nums[mid] == nums[mid + 1])) {
                // Pattern is unbroken up to mid -> search the right half
                low = mid + 1;
            } else {
                // Pattern is broken before mid -> unique element is at or before mid
                high = mid - 1;
            }
        }

        // Should not be reached if input is valid (exactly one non-duplicate exists)
        return -1;
    }
};