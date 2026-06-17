// T.C: O(K*N(Target/m)), Reasoning: The time complexity of this algorithm is O(K*N(Target/m)), where K is the average length of each combination, N is the number of candidates, Target is the target sum, and m is the minimum value among the candidates. This is because we explore all possible combinations of candidates that can sum up to the target, and for each combination, we may have to explore multiple paths due to the recursive nature of the solution.
// S.C: O(Target/m), Reasoning: The space complexity is O(Target/m) due to the maximum depth of the recursion tree, which is at most Target/m (when the smallest candidate is used repeatedly).
// Question Link: https://takeuforward.org/plus/dsa/problems/combination-sum?source=strivers-sde-sheet

class Solution {
   public:
    // Recursive helper that explores every way to build a combination
    // summing to "sum" using candidates[0..i] (with repetition allowed).
    // v   -> original candidates array
    // i   -> only candidates[0..i] are allowed to be used at this point
    // sum -> remaining amount still needed to reach the target
    // v2  -> the combination being built right now (shared buffer, mutated in place)
    // ans -> collects every valid combination found
    void func(vector<int>& v, int i, int sum, vector<int>& v2,
              vector<vector<int>>& ans) {

        // Hit the target exactly -> v2 is a complete, valid combination
        if (sum == 0) {
            ans.push_back(v2);   // copy v2 into ans (v2 itself keeps changing later)
            return;
        }

        // Overshot the target -> this path can never work, abandon it
        if (sum < 0) {
            return;
        }

        // Ran out of candidates to consider -> dead end
        if (i < 0) {
            return;
        }

        // Choice 1: TAKE candidates[i] (explored first this time)
        v2.push_back(v[i]);

        // Pass "i" again (not "i-1") so the same value can be reused
        // multiple times in the same combination
        func(v, i, sum - v[i], v2, ans);

        // Backtrack: undo the "take" so v2 is clean before trying the next choice
        v2.pop_back();

        // Choice 2: SKIP candidates[i] entirely, move to the previous index
        func(v, i - 1, sum, v2, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;   // temporary buffer to build one combination at a time

        // Start from the last index, with the full target as the remaining sum
        func(candidates, candidates.size() - 1, target, v, ans);
        return ans;
    }
};