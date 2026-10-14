class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n= jobDifficulty.size();

        if(n<d) return -1;

        vector<vector<int>> dp(d+1, vector<int>(n+1, INT_MAX));
        dp[0][0]=0;

        for(int day=1; day<=d; day++){
            for(int i=day; i<=n; i++){
                int maxJob=0;

                for(int j=i-1; j>= day-1; j--){
                    maxJob= max(maxJob, jobDifficulty[j]);

                    if(dp[day-1][j]!= INT_MAX)
                        dp[day][i]= min(dp[day][i], dp[day-1][j]+ maxJob);
                }
            }
        }
        return dp[d][n];
    }
};