class Solution {
public:
    vector<vector<int>> dp;

    int solve(vector<int>& nums, int l, int r){
        if(l==r) return nums[l];

        if(dp[l][r]!= INT_MIN) 
            return dp[l][r];

        int takeLeft= nums[l]- solve(nums, l+1, r);
        int takeright= nums[r]- solve(nums, l, r-1);

        return dp[l][r]= max(takeLeft, takeright);  
    }

    bool predictTheWinner(vector<int>& nums) {
        int n= nums.size();

        dp.assign(n, vector<int>(n, INT_MIN));

        return solve(nums, 0, n-1)>= 0;
    }
};