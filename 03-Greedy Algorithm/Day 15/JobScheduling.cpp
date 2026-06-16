// T.C: O(N log N + N × M), Reason: O(N log N)  → sorting jobs by profit, O(N × M)    → the nested loop  N = number of jobs, M = maxDeadline
// S.C: O(M), Reason: O(M) → Hash array of size maxDeadline
// Question Link: https://takeuforward.org/plus/dsa/problems/job-sequencing-problem?source=strivers-sde-sheet

class Solution {
   public:
    // Sort jobs in descending order of profit
    // so we greedily consider the most profitable jobs first
    static bool comparator(const vector<int>& a, const vector<int>& b) {
        return a[2] > b[2];
    }

    // Each job is represented as {id, deadline, profit}
    //                              [0]    [1]      [2]
    vector<int> JobScheduling(vector<vector<int>>& Jobs) {
        // Step 1: Sort jobs by profit (highest first)
        sort(Jobs.begin(), Jobs.end(), comparator);

        int n = Jobs.size();

        // Step 2: Find the maximum deadline across all jobs
        // This tells us the size of our scheduling window
        int maxDeadline = -1;
        for (auto it : Jobs) {
            maxDeadline = max(maxDeadline, it[1]);
        }

        // Step 3: Create a slot array to track which job is assigned to each
        // time slot hash[j] == -1 means slot j is free Slots are 0-indexed,
        // representing time slots 1 to maxDeadline
        vector<int> hash(maxDeadline, -1);

        int cnt = 0;          // number of jobs successfully scheduled
        int totalProfit = 0;  // total profit from scheduled jobs

        // Step 4: Greedily assign each job to the latest available slot before
        // its deadline
        for (int i = 0; i < n; i++) {
            // Try to fit this job as late as possible (to keep earlier slots
            // free for other jobs) Start from deadline-1 (0-indexed) and go
            // backwards
            for (int j = Jobs[i][1] - 1; j >= 0; j--) {
                if (hash[j] == -1) {            // found a free slot
                    cnt++;                      // one more job scheduled
                    totalProfit += Jobs[i][2];  // add its profit
                    hash[j] = Jobs[i][0];  // mark slot as taken by this job's id
                    break;           // move to the next job
                }
                // if slot is occupied, try the previous slot
            }
            // if no free slot found before deadline, this job is skipped
        }

        return {cnt, totalProfit};
    }
};


