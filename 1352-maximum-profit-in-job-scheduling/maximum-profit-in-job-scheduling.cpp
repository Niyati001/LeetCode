
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();

        vector<array<int, 3>> jobs(n);

        for (int i = 0; i < n; i++) {
            jobs[i] = {endTime[i], startTime[i], profit[i]};
        }

        // Sort by end time
        sort(jobs.begin(), jobs.end());

        vector<int> ends(n);
        for (int i = 0; i < n; i++) {
            ends[i] = jobs[i][0];
        }

        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            int start = jobs[i - 1][1];
            int end = jobs[i - 1][0];
            int money = jobs[i - 1][2];

            // Number of earlier jobs ending <= start
            int p = lower_bound(ends.begin(), ends.begin() + i - 1,
            start + 1) - ends.begin();

            int take = money + dp[p];
            int skip = dp[i - 1];

            dp[i] = max(take, skip);
        }

        return dp[n];
    }
};
