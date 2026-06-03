//T.C: O(N^logN) + O(N) = O(N^logN) {Sorting + Merging}
//S.C: O(n) {Auxiliary Space for Merging}
//Link: https://takeuforward.org/plus/dsa/problems/merge-overlapping-subintervals?source=strivers-sde-sheet

class Solution {
   public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        int n = arr.size();
        if (arr.empty()) return {};
        vector<vector<int>> ans;
        // sort
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n; i++) {
            // current interval does not lie in the last interval
            if (ans.empty() || arr[i][0] > ans.back()[1]) {
                // new interval added
                ans.push_back(arr[i]);
            } else {
                // lies - means mearged
                ans.back()[1] = max(ans.back()[1], arr[i][1]);
            }
        }
        return ans;
    }
};