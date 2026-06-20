// T.C:  O(log(max - min + 1)) * O(N * logM)
// S.C: O(1)
// Question Link: https://takeuforward.org/plus/dsa/problems/matrix-median?source=strivers-sde-sheet

class Solution {
   private:
    // Standard "upper bound" binary search:
    // Finds the index of the first element in arr that is strictly greater than x.
    // This index also equals the count of elements <= x in the row (since row is sorted).
    int upperBound(vector<int>& arr, int x, int m) {
        int low = 0, high = m - 1;
        int ans = m; // default: if all elements are <= x, "first greater" is past the end

        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] > x) {
                ans = mid;      // candidate found, but look further left for an earlier one
                high = mid - 1;
            } else {
                low = mid + 1;  // arr[mid] <= x, so move right
            }
        }
        return ans; // count of elements in arr that are <= x
    }

    // Counts how many elements in the entire matrix are <= x,
    // by summing up upperBound results across all rows.
    int countSmallEqual(vector<vector<int>>& matrix, int n, int m, int x) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += upperBound(matrix[i], x, m);
        }
        return cnt;
    }

   public:
    int findMedian(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        // Determine the overall value range [low, high] to binary search over.
        // Since each row is sorted, the smallest element of a row is at index 0,
        // and the largest is at index m-1.
        int low = INT_MAX, high = INT_MIN;
        for (int i = 0; i < n; i++) {
            low = min(low, matrix[i][0]);     // smallest value among row starts
            high = max(high, matrix[i][m - 1]); // largest value among row ends
        }

        // The median position in the fully merged sorted sequence (0-indexed).
        // For n*m elements (assumed odd total count, typical for this problem),
        // this is the index of the median element.
        int req = (n * m) / 2;

        // Binary search on the answer (the median value itself)
        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Count how many elements in the matrix are <= mid
            int smallEqual = countSmallEqual(matrix, n, m, mid);

            if (smallEqual <= req) {
                // Not enough elements <= mid to reach the median position,
                // so the median must be larger -> search the right half
                low = mid + 1;
            } else {
                // Too many elements <= mid, median could be mid or smaller
                // -> search the left half
                high = mid - 1;
            }
        }

        // When the loop ends, low is the smallest value for which
        // countSmallEqual(low) > req, i.e., the median value.
        return low;
    }
};