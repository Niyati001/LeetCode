class Solution {
public:
    vector<vector<int>> jobs;
    vector<int> dp;

    int solve(int i){
        if(i== jobs.size()) return 0;

        if(dp[i]!= -1) return dp[i];
        
        //Not take current job
        int skip= solve(i+1);
 
        // Take current job
        int end= jobs[i][1];
        int profit= jobs[i][2];

        int low= i+1;
        int high= jobs.size()-1;

        int next= jobs.size();

        while(low<= high){
            int mid= low+ (high-low)/2;

            if(jobs[mid][0]>= end){
                next= mid;
                high= mid-1;
            }
            else{
                low= mid+1;
            }
        }
        int take= profit+ solve(next);
        
        return dp[i]= max(skip, take);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n= startTime.size();
        jobs.resize(n);

        for(int i=0; i<n; i++){
            jobs[i]= {startTime[i], endTime[i], profit[i]};
        }

        sort(jobs.begin(), jobs.end());
        dp.assign(n, -1);

        return solve(0);
    }
};