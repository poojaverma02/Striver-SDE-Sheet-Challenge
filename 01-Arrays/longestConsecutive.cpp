// T.C: O(N) + O(2xN) ~ O(3xN) reason: O(N) for inserting the elements in the set and O(2xN) for traversing the array twice, once for checking if the element is the starting point of a sequence and once for counting the length of the sequence
// S.C:  O(N) for the set to store the unique elements of the array
// Question Link: https://takeuforward.org/plus/dsa/problems/longest-consecutive-sequence-in-an-array?source=strivers-sde-sheet

class Solution {
   public:
    // The idea is to store all elements in a set, then iterate through the set
    // and check whether the previous element exists or not.
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int longest = 1;
        unordered_set<int> st;
        // put all elements in set
        for (int i = 0; i < n; i++) {
            st.insert(nums[i]);
        }
        // traverse on set
        for (auto it : st) {
            // Checking that current element is starting no. or not
            if (st.find(it - 1) == st.end()) {
                int cnt = 1;
                int x = it;
                // find consecutive numbers
                while (st.find(x + 1) != st.end()) {
                    // Move next element in the sequence
                    x = x + 1;

                    cnt = cnt + 1;
                }

                longest = max(longest, cnt);
            }
        }
        return longest;
    }
};

