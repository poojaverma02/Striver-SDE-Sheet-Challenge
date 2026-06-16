// T.C: O(C)
// S.C: O(1)
// Question Link: https://takeuforward.org/plus/dsa/problems/pascals-triangle-i?source=strivers-sde-sheet  

class Solution {
   public:
    int pascalTriangleI(int r, int c) { return nCr(r - 1, c - 1); }

   private:
    int nCr(int n, int r) {
        if (r > n - r) r = n - r;

        if (r == 1) return n;

        int res = 1;

        for (int i = 0; i < r; i++) {
            res = res * (n - i);
            res = res / (i + 1);
        }

        return res;
    }
};
