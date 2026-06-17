// T.C: O(2^N * N), where N is the number of coins.
// At each step, we explore two choices (include or exclude), leading to 2^N possible subsets. For each valid subset, copying the current combination into the result takes up to O(N), giving the total complexity as O(2^N * N) in the worst case.
// S.C: O(N), due to the recursion stack depth and storage for the current combination.
// Question Link: https://takeuforward.org/plus/dsa/problems/combination-sum-ii?source=strivers-sde-sheet


class Solution {
public:
    // Recursive helper exploring combinations from sorted candidates.
    // v   -> sorted candidates array
    // i   -> we may only use candidates[0..i] at this point
    // sum -> remaining amount still needed to reach the target
    // v2  -> combination being built right now (shared buffer, mutated in place)
    // ans -> collects every valid, duplicate-free combination found
    void func(vector<int>& v, int i, int sum, vector<int>& v2, vector<vector<int>>& ans) {

        // Hit the target exactly -> v2 is a complete, valid combination
        if (sum == 0) {
            ans.push_back(v2);   // copy v2 into ans
            return;
        }

        // Overshot the target, or ran out of candidates -> dead end
        if (sum < 0 || i < 0) return;

        // ---- Choice 1: TAKE candidates[i] ----
        v2.push_back(v[i]);

        // Move to i-1 (not i!) since each element can only be used once here
        func(v, i - 1, sum - v[i], v2, ans);

        // Backtrack: undo the take before trying the next choice
        v2.pop_back();

        // ---- Choice 2: SKIP candidates[i] ENTIRELY, including all its duplicates ----
        // Walk backwards from i-1 looking for the first value different from v[i].
        // This is what prevents duplicate combinations: if we just skipped to i-1
        // normally, we could end up "taking or not taking" the same duplicate value
        // in different branches and produce the same combination multiple times.
        for (int ind = i - 1; ind >= 0; ind--) {
            if (v[ind] != v[i]) {
                func(v, ind, sum, v2, ans);  // recurse starting after all duplicates of v[i]
                break;                       // only need to do this once
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;

        // Sorting is essential here: it groups duplicates together so the
        // "skip all duplicates" loop in func() works correctly
        sort(candidates.begin(), candidates.end());

        func(candidates, candidates.size() - 1, target, v, ans);
        return ans;
    }
};