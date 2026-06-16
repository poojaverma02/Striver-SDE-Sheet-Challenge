// T.C: O(log(N*M))
// S.C: O(1)
// Question Link: https://takeuforward.org/plus/dsa/problems/search-in-a-2d-matrix?source=strivers-sde-sheet

class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size();
        int m = mat[0].size();

        // Virtual index range over the flattened matrix [0, n*m - 1]
        int low = 0, high = n * m - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            // Convert the flat 1D index back to 2D matrix coordinates.
            // Integer division gives the row; modulo gives the column.
            int row = mid / m;
            int col = mid % m;

            if (mat[row][col] == target) {
                // Target found
                return true;
            } else if (mat[row][col] < target) {
                // Target lies in the right half
                low = mid + 1;
            } else {
                // Target lies in the left half
                high = mid - 1;
            }
        }

        return false;
    }
};