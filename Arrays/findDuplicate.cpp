// T.C: O(N)
// S.C: O(1)
// Question Link: https://takeuforward.org/plus/dsa/problems/find-the-duplicate-number?source=strivers-sde-sheet

class Solution {
   public:
    int findDuplicate(vector<int>& nums) {
        // Step 1: Detect Cycle
        int slow = nums[0];
        int fast = nums[0];
        //  I am using a while loop, and both slow and fast pointers are
        //  initially pointing to the first element.
        //  Therefore, I move them explicitly before entering the loop;
        //  otherwise, the while loop won't execute as intended. If you want to
        //  avoid this extra step, you can use a do-while loop instead.
        slow = nums[slow];
        fast = nums[nums[fast]];

        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        // Step 2: Find cycle entry point (= duplicate)
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        // return anything slow or fast becoz both are same now
        return fast;
    }
};
