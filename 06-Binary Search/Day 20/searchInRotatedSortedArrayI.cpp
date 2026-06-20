// T.C: O(logN)
// S.C: O(1)
// Question Link: https://takeuforward.org/plus/dsa/problems/search-in-rotated-sorted-array-i?source=strivers-sde-sheet

class Solution {
public:
    int search(vector<int> &nums, int k) {
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            // Found the target
            if (nums[mid] == k) return mid;

            // Determine which half [low...mid] or [mid...high] is sorted.
            // In a rotated sorted array, at least one half is always sorted.
            if (nums[low] <= nums[mid]) {
                // Left half [low...mid] is sorted

                if (nums[low] <= k && k <= nums[mid]) {
                    // k lies within the sorted left half -> search left
                    high = mid - 1;
                } else {
                    // k is outside the left half's range -> must be in right half
                    low = mid + 1;
                }
            } else {
                // Right half [mid...high] is sorted instead

                if (nums[mid] <= k && k <= nums[high]) {
                    // k lies within the sorted right half -> search right
                    low = mid + 1;
                } else {
                    // k is outside the right half's range -> must be in left half
                    high = mid - 1;
                }
            }
        }

        // Target not found in the array
        return -1;
    }
};