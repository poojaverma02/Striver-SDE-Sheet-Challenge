// T.C: O(N)
// S.C: O(1)
// Question Link: https://takeuforward.org/plus/dsa/problems/find-the-repeating-and-missing-number?source=strivers-sde-sheet

class Solution {
   public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {
        long long n = nums.size();

        // Sum of first n natural numbers: 1+2+...+n
        long long sn = (n * (n + 1)) / 2;

        // Sum of squares of first n natural numbers: 1²+2²+...+n²
        long long s2n = (n * (n + 1) * (2 * n + 1)) / 6;

        long long s = 0, s2 = 0;
        for (int i = 0; i < n; i++) {
            s += nums[i];  // actual sum of array
            s2 += (long long)nums[i] *
                  (long long)nums[i];  // actual sum of squares
        }

        // Let x = repeating number, y = missing number
        // s  - sn  = x - y          → val1 = x - y
        // s2 - s2n = x² - y²        → val2 = x² - y²
        long long val1 = s - sn;    // x - y
        long long val2 = s2 - s2n;  // x² - y²

        // x² - y² = (x+y)(x-y)
        // so (x+y) = (x²-y²) / (x-y)
        val2 = val2 / val1;  // val2 is now x + y

        // Solve the two equations:
        // x - y = val1
        // x + y = val2
        // Adding both:   2x = val1 + val2  →  x = (val1 + val2) / 2
        // Subtracting:   2y = val2 - val1  →  y = x - val1
        long long x = (val1 + val2) / 2;  // repeating number
        long long y = x - val1;           // missing number

        return {(int)x, (int)y};
    }
};