// T.C: O(2N) + O(NlogN), Reason: O(2N) for storing and checking the start and end time of the meetings in a vector of pairs and O(NlogN) for sorting the vector of pairs based on the end time of the meetings.
// S.C: O(N), Reason: O(N) for storing the start and end time of the meetings in a vector of pairs.
// Question Link: https://takeuforward.org/plus/dsa/problems/n-meetings-in-one-room?source=strivers-sde-sheet

class Solution
{
public:
  // Custom comparator to sort meetings by their end time (ascending)
  // This is static so it can be passed directly to sort() without needing an
  // object
  static bool comparator(const pair<int, int> &a, const pair<int, int> &b)
  {
    return a.second < b.second;
  }

  int maxMeetings(vector<int> &start, vector<int> &end)
  {
    int n = start.size();

    // Pair up each meeting's start and end time together for easier sorting
    vector<pair<int, int>> meetings;
    for (int i = 0; i < n; i++)
    {
      meetings.push_back({start[i], end[i]});
    }

    // Sort meetings by end time — greedy strategy:
    // attending the meeting that ends earliest leaves maximum room for
    // future meetings
    sort(meetings.begin(), meetings.end(), comparator);

    // Always attend the first meeting (it ends the earliest after sorting)
    int freeTime =
        meetings[0].second; // track when the last attended meeting ends
    int count = 1;          // we've attended 1 meeting so far

    // Greedily pick the next meeting that starts after the current one ends
    for (int i = 1; i < n; i++)
    {
      if (meetings[i].first >
          freeTime)
      { // no overlap with last attended meeting
        freeTime =
            meetings[i]
                .second; // update free time to this meeting's end
        count++;         // attend this meeting
      }
      // else: skip this meeting — it overlaps with the last attended one
    }

    return count; // maximum number of non-overlapping meetings we can attend
                
  }
};