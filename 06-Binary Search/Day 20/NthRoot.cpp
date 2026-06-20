// T.C: O(logM * logN)
// S.C: O(1)
// Question Link: https://takeuforward.org/plus/dsa/problems/find-nth-root-of-a-number?source=strivers-sde-sheet

class Solution {
   private:
    // Computes mid^n and compares it to m, while avoiding overflow.
    // Returns:
    //   0 -> mid^n < m
    //   1 -> mid^n == m
    //   2 -> mid^n > m
    int func(int mid, int n, int m) {
        long long ans = 1, base = mid;

        // Fast exponentiation (binary exponentiation) to compute mid^n
        while (n > 0) {
            if (n % 2) {
                // n is odd: multiply current base into ans
                ans = ans * base;

                // Early exit: if ans already exceeds m, no need to continue.
                // This also prevents potential overflow from further multiplications.
                if (ans > m) return 2;

                n--; // reduce the odd exponent by 1 to make it even
            } else {
                // n is even: halve the exponent and square the base instead
                n /= 2;
                base = base * base;

                // Early exit: if base already exceeds m, mid^n will definitely exceed m
                if (base > m) return 2;
            }
        }

        // Loop finished without exceeding m, so compare the final result
        if (ans == m) return 1;  // exact match: mid is the Nth root
        return 0;                // ans < m: mid^n is too small
    }

   public:
    // Finds the integer Nth root of M, i.e., an integer x such that x^N == M.
    // Returns -1 if no such integer exists.
    int NthRoot(int N, int M) {
        int low = 1, high = M; // search space: possible values of the Nth root

        // Binary search for x such that x^N == M
        while (low <= high) {
            int mid = (low + high) / 2;
            int midN = func(mid, N, M); // check mid^N vs M

            if (midN == 1) {
                // mid^N == M, found the exact Nth root
                return mid;
            } else if (midN == 0) {
                // mid^N < M, need a larger candidate
                low = mid + 1;
            } else {
                // mid^N > M, need a smaller candidate
                high = mid - 1;
            }
        }

        // No integer x found such that x^N == M
        return -1;
    }
};