class Solution {
public:
    vector<vector<vector<int>>> dp;

    int solve(vector<vector<int>>& coins, int i, int j, int used) {
        int m = coins.size();
        int n = coins[0].size();

        if(i >= m || j >= n)
            return -1e9;

        if(i == m-1 && j == n-1) {
            int ans = coins[i][j];

            if(coins[i][j] < 0 && used < 2)
                ans = 0;

            return ans;
        }

        if(dp[i][j][used] != -1e9)
            return dp[i][j][used];

        int ans = -1e9;

        // Don't neutralize
        ans = coins[i][j] + max(
            solve(coins, i+1, j, used),
            solve(coins, i, j+1, used)
        );

        // Neutralize robber
        if(coins[i][j] < 0 && used < 2) {
            ans = max(ans,
                max(
                    solve(coins, i+1, j, used+1),
                    solve(coins, i, j+1, used+1)
                )
            );
        }

        return dp[i][j][used] = ans;
    }

    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();

        dp.assign(m, vector<vector<int>>(n, vector<int>(3, -1e9)));

        return solve(coins, 0, 0, 0);
    }
};