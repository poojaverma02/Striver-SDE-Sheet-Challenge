// T.C: O(2N) + O(NlogN), Reason: O(2N) for traversal in both arrays and O(NlogN) for sorting
// S.C: O(1), Reason: We are not using any extra space apart from the input arrays
// Question Link: https://takeuforward.org/plus/dsa/problems/minimum-number-of-platforms-required-for-a-railway?source=strivers-sde-sheet

class Solution
{
public:
  int findPlatform(vector<int> &Arrival, vector<int> &Departure)
  {
    int n = Arrival.size();

    // Sort both arrays independently so we can use a two-pointer approach
    // Note: after sorting, Arrival[i] and Departure[i] no longer belong to
    // the same train
    sort(Arrival.begin(), Arrival.end());
    sort(Departure.begin(), Departure.end());

    int ans = 1; // we always need at least 1 platform
    int count = 1;     // current platforms in use (first train has already arrived)
    int i = 1; // pointer for Arrival array (start from 2nd train)
    int j = 0; // pointer for Departure array

    // Process events in chronological order using two pointers
    while (i < n && j < n)
    {
      if (Arrival[i] <= Departure[j])
      {
        // A new train arrives before the earliest departing train
        // leaves → need one more platform
        count++;
        i++;
      }
      else
      {
        // A train departs before the next arrival
        // → one platform is freed up
        count--;
        j++;
      }

      // Track the maximum platforms needed at any point in time
      ans = max(ans, count);
    }

    return ans; // minimum number of platforms required
  }
};