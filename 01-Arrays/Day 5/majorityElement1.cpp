// T.C: O(2N)
// S.C: O(1)
// Question Link: https://takeuforward.org/plus/dsa/problems/majority-element-i?source=strivers-sde-sheet

class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        // ── Phase 1: Boyer-Moore Voting Algorithm ──────────────────────────
        // Intuition: majority element (appears > n/2 times) will always
        // "outlast" all other elements when votes cancel each other out.
        // Think of it as every majority vote cancelling one non-majority vote;
        // since majority has more than half, it survives till the end.

        int cnt = 0;
        int el;

        for (int i = 0; i < n; i++) {
            if (cnt == 0) {
                // No current candidate — nominate this element
                cnt = 1;
                el = nums[i];
            } else if (el == nums[i]) {
                // Same as current candidate — strengthen its lead
                cnt++;
            } else {
                // Different element — cancel out one vote against the candidate
                cnt--;
            }
        }

        // ── Phase 2: Verification ──────────────────────────────────────────
        // Phase 1 only guarantees a candidate, not a majority.
        // e.g. [1, 2, 3] → candidate = 3, but no majority exists.
        // So we confirm by counting actual occurrences.

        int cnt1 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == el) cnt1++;
        }

        // Majority element must appear more than floor(n/2) times
        if (cnt1 > (n / 2)) return el;

        // No majority element exists in the array
        return -1;
    }
};