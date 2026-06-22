// T.C: O(k log k)
// S.C: O(k)
// Question Link: https://takeuforward.org/plus/dsa/problems/maximum-sum-combination?source=strivers-sde-sheet

class Solution {
public:
  vector<int> maxSumCombinations(vector<int> &nums1, vector<int> &nums2, int k) {
    // Sort both arrays in descending order
    sort(nums1.begin(), nums1.end(), greater<int>());
    sort(nums2.begin(), nums2.end(), greater<int>());

    // Max heap to store {sum, {i, j}}
    priority_queue<pair<int, pair<int, int>>> pq;
    set<pair<int, int>> visited;

    // Push first pair
    pq.push({nums1[0] + nums2[0], {0, 0}});
    visited.insert({0, 0});

    vector<int> res;

    // Extract k largest sums
    while (k-- && !pq.empty()) {
      auto [sum, idx] = pq.top(); pq.pop();
      int i = idx.first, j = idx.second;
      res.push_back(sum);

      // Move to next element in nums1
      if (i + 1 < nums1.size() && !visited.count({i + 1, j})) {
        pq.push({nums1[i + 1] + nums2[j], {i + 1, j}});
        visited.insert({i + 1, j});
      }

      // Move to next element in nums2
      if (j + 1 < nums2.size() && !visited.count({i, j + 1})) {
        pq.push({nums1[i] + nums2[j + 1], {i, j + 1}});
        visited.insert({i, j + 1});
      }
    }
    return res;
  }
};



