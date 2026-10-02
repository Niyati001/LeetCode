class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;

        for(int x: nums){
            sum+= x;
        }

        if(abs(target)> sum) return 0;
        if((sum+ target)%2!=0) return 0;

        int required= (sum+ target)/2;

        vector<int> dp(required+1, 0);
        dp[0]=1;

        for(int num: nums){
            for(int j=required; j>= num; j--){
                dp[j]+= dp[j- num];
            }
        }
        return dp[required];
    }
};