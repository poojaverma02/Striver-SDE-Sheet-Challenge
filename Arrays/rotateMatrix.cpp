//T.C: O(N^2) + O(N^2) = O(N^2) {Transpose + Reverse}
//S.C: O(1)
//Link: https://takeuforward.org/plus/dsa/problems/rotate-matrix-by-90-degrees?source=strivers-sde-sheet

class Solution {
   public:
    void rotateMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // Transpose the matrix ->column becomes row
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // reverse the matrix
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};