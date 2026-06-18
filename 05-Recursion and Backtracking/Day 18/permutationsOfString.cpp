// T.C: O(n! * n)
// S.C: O(n) auxiliary space for recursion depth and the used/current buffers, plus O(n! · n) for the output itself.
// Question Link: https://takeuforward.org/plus/dsa/problems/permutations-of-a-string?source=strivers-sde-sheet

class Solution {
public:
    vector<string> permuteUnique(string s) {
        // Step 1: Sort the characters of the string.
        // This does two things:
        //   (a) Groups identical characters together, so duplicate
        //       permutations can be detected and skipped easily.
        //   (b) Guarantees permutations come out in lexicographically
        //       sorted order, since we always try characters left to
        //       right in their sorted positions.
        sort(s.begin(), s.end());

        int n = s.size();

        // used[i] = true means the character at index i is currently
        // part of the permutation being built in this recursive branch.
        vector<bool> used(n, false);

        // The permutation currently being constructed, one character
        // at a time, via backtracking.
        string current;

        // Collects every complete, unique permutation found.
        vector<string> result;

        backtrack(s, used, current, result, n);
        return result;
    }

private:
    // Recursive backtracking helper.
    // s       - the sorted input string (characters to permute)
    // used    - tracks which indices are already placed in `current`
    // current - the permutation being built so far
    // result  - accumulates finished permutations
    // n       - total length of the string
    void backtrack(const string& s, vector<bool>& used, string& current,
                    vector<string>& result, int n) {
        // Base case: once `current` has n characters, it's a complete
        // permutation, so save a copy of it and return.
        if ((int)current.size() == n) {
            result.push_back(current);
            return;
        }

        // Try placing each character at the next position.
        for (int i = 0; i < n; i++) {
            // Skip characters already used in this branch.
            if (used[i]) continue;

            // Duplicate-skipping rule:
            // If the current character is the same as the previous one
            // AND the previous one is NOT used in this branch, then
            // placing this character now would just repeat a
            // permutation already explored by an earlier branch
            // (where the previous identical character was placed
            // first). So we skip it.
            //
            // This only allows identical characters to be used in
            // left-to-right order within sorted duplicate groups,
            // which eliminates duplicate permutations without
            // needing a set for deduplication afterward.
            if (i > 0 && s[i] == s[i - 1] && !used[i - 1]) continue;

            // Choose: mark this character as used and append it.
            used[i] = true;
            current.push_back(s[i]);

            // Explore: recurse to fill the remaining positions.
            backtrack(s, used, current, result, n);

            // Un-choose (backtrack): remove the character and mark
            // it unused again, so other branches can try it in
            // different positions.
            current.pop_back();
            used[i] = false;
        }
    }
};

