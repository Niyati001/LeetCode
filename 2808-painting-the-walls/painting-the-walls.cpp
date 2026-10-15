class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n=cost.size();
        const int INF= 1e9;

        vector<int> dp(n+1, INF);

        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            for (int j = n; j >= 1; j--) {
                int prev = max(0, j - time[i] - 1);
                if (dp[prev] != INF) {
                    dp[j] = min(dp[j], dp[prev] + cost[i]);
                }
            }
        }

        return dp[n];
    }
};