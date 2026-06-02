// T.C: O(N)
// S.C: O(1)
// Question Link: https://takeuforward.org/plus/dsa/problems/best-time-to-buy-and-sell-stock?source=strivers-sde-sheet

class Solution {
   public:
    int stockBuySell(vector<int> arr, int n) {
        // Keep Track of min element from left
        int maxPro = 0;
        int minPrice = INT_MAX;
        for (int i = 0; i < n; i++) {
            minPrice = min(minPrice, arr[i]);
            maxPro = max(maxPro, arr[i] - minPrice);
        }
        return maxPro;
    }
};
