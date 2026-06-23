// T.C: O(k² log k),
// S.C: O(k)
// Question Link: https://takeuforward.org/plus/dsa/problems/merge-k-sorted-arrays?source=strivers-sde-sheet

class Solution {
public:
    vector<int> mergeKSortedArrays(vector<vector<int>>& arr, int k) {
        
        // Stores the final merged sorted array
        vector<int> result;

        // Min Heap
        // Format: {value, {row, col}}
        // value = actual element
        // row   = which array the element belongs to
        // col   = index of the element within that array
        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;

        // Push the first element of every array into the min heap
        for (int i = 0; i < k; i++) {
            if (!arr[i].empty()) {
                pq.push({arr[i][0], {i, 0}});
            }
        }

        // Process until all elements are extracted
        while (!pq.empty()) {

            // Get the smallest element from the heap
            auto top = pq.top();
            pq.pop();

            int val = top.first;               // Current smallest value
            int row = top.second.first;        // Array number
            int col = top.second.second;       // Index inside that array

            // Add the smallest element to the answer
            result.push_back(val);

            // Push the next element from the same array (if it exists)
            if (col + 1 < arr[row].size()) {
                pq.push({arr[row][col + 1], {row, col + 1}});
            }
        }

        // Return the fully merged sorted array
        return result;
    }
};
