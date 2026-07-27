// T.C: O(nlogn)
// S.C: O(n)
// Question Link: https://takeuforward.org/plus/dsa/problems/maximum-profit-in-job-scheduling?source=strivers-sde-sheet

class Solution{
public:
    // Function to find latest non-conflicting job using binary search
    int latestNonConflict(vector<Job>& jobs, int i) {
        int low = 0;
        int high = i - 1;
        int ans = -1;

        // Binary search loop
        while (low <= high) {
            int mid = (low + high) / 2;
            if (jobs[mid].end <= jobs[i].start) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

    // Function to compute maximum profit using tabulation
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();

        // Array of jobs
        vector<Job> jobs(n);

        // Initialize jobs
        for (int i = 0; i < n; i++) jobs[i] = {startTime[i], endTime[i], profit[i]};

        // Sort jobs by end time
        sort(jobs.begin(), jobs.end(), [](Job &a, Job &b){ return a.end < b.end; });

        // DP array for storing max profit
        vector<int> dp(n);
        dp[0] = jobs[0].profit;

        // Tabulation loop
        for (int i = 1; i < n; i++) {
            int inclProf = jobs[i].profit;
            int l = latestNonConflict(jobs, i);
            if (l != -1) inclProf += dp[l];
            dp[i] = max(inclProf, dp[i - 1]);
        }

        return dp[n-1];
    }
};