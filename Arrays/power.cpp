// T.C: O(log N)
// S.C: O(1)
// Question Link: https://takeuforward.org/plus/dsa/problems/pow(x,n)?source=strivers-sde-sheet

class Solution {
   public:
    double myPow(double x, int n) {
        long long num = n;
        if (num < 0) {
            x = 1.0 / x;
            num = -num;
        }

        double result = 1.0;

        // Process each bit of the exponent.
        // If the current bit is set, multiply result by the current base power.
        // Square the base at every step regardless.
        // e.g. x^13 = x^(1101₂) = x^8 * x^4 * x^1
        while (num > 0) {
            if (num % 2 == 1) result *= x;  // odd: current bit is set
            x *= x;                         // square the base
            num /= 2;                       // shift to next bit
        }

        return result;
    }
};