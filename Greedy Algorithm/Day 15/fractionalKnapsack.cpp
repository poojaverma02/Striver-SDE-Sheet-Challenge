// T.C: O(N log N + N) ~ O(N log N), Reason: O(N log N) for sorting the items by their value-to-weight ratio and O(N) for traversal 
// S.C: O(N), Reason: We are using a vector to store the ratio of value to weight for each item
// Question Link: https://takeuforward.org/plus/dsa/problems/fractional-knapsack?source=strivers-sde-sheet

class Solution {
   public:
    double fractionalKnapsack(vector<long long>& val, vector<long long>& wt,
                              long long capacity) {
        // Step 1: Compute value-to-weight ratio for each item
        // Store as {ratio, index} so we can refer back to original val[] and
        // wt[]
        vector<pair<double, int>> ratio;
        for (int i = 0; i < val.size(); i++) {
            ratio.push_back({(double)val[i] / wt[i], i});
        }

        // Step 2: Sort items by ratio in descending order
        // Greedy strategy: pick the most "valuable per kg" item first
        sort(ratio.rbegin(), ratio.rend());

        double totalValue = 0.0;

        // Step 3: Greedily fill the knapsack
        for (auto& r : ratio) {
            int i = r.second;  // original index of this item

            if (wt[i] <= capacity) {
                // Item fits completely → take the whole item
                totalValue += val[i];
                capacity -= wt[i];
            } else {
                // Item doesn't fit fully → take the fraction that fits
                // value gained = val[i] * (remaining capacity / item weight)
                totalValue += val[i] * ((double)capacity / wt[i]);
                break;  // knapsack is now full, no point checking further
            }
        }

        // Round to 6 decimal places to avoid floating point precision issues
        return round(totalValue * 1e6) / 1e6;
    }
};