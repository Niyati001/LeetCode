class Solution {
public:
    vector<vector<long long>> dp;
    long long solve(int i, int j, vector<int> &robot, vector<vector<int>> &factory){
        //all robots repaired
        if(i== robot.size()) return 0;

        //no factory left
        if(j== factory.size()) return 1e18;

        if(dp[i][j]!= -1){
            return dp[i][j];
        }

        long long ans= solve(i, j+1, robot, factory);

        long long cost=0;

        for(int k=0; k<factory[j][1] && i+k< robot.size(); k++){
            cost+= abs(robot[i+k]- factory[j][0]);
            ans= min(ans, cost+ solve(i+k+1, j+1, robot,factory));
        }
        return dp[i][j]= ans;
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        dp.resize(robot.size()+1, vector<long long> (factory.size()+1, -1));
        return solve(0,0, robot, factory);
    }
};